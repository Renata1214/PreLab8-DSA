#include <iostream>
#include <vector>
#include <string>
#include <memory>

static int leafID = 0;

class Node {
public:
    int m, n;
    bool isLeaf;
    int leafValue;
    std::vector<std::shared_ptr<Node>> children;
    int id;  // Only used for leaf nodes

    Node(int m, int n, bool isLeaf=false, int leafValue=0)
    : m(m), n(n), isLeaf(isLeaf), leafValue(leafValue), id(-1) {
        if (isLeaf) {
            id = leafID++;
        }
    }
};

class AckermannTree {
private:
    std::shared_ptr<Node> root;

    std::shared_ptr<Node> buildTree(int m, int n) {
        if (m == 0) {
            return std::make_shared<Node>(m, n, true, n + 1);
        } else if (m > 0 && n == 0) {
            auto node = std::make_shared<Node>(m, n);
            node->children.push_back(buildTree(m - 1, 1));
            return node;
        } else if (m > 0 && n > 0) {
            auto node = std::make_shared<Node>(m, n);
            auto firstChild = buildTree(m, n - 1);
            node->children.push_back(firstChild);
            int secondChildVal = firstChild->isLeaf ? firstChild->leafValue : 0; // Simplification
            auto secondChild = buildTree(m - 1, secondChildVal);
            node->children.push_back(secondChild);
            return node;
        }
        // Fallback, should never hit this
        return std::make_shared<Node>(0, 0, true, 0);
    }

    void printEdges(const std::shared_ptr<Node>& node, const std::string& prefix = "") const {
        if (node->isLeaf) {
            std::cout << prefix << " --> " << node->m << "(" << node->n << ")" << std::endl;
        } else {
            std::string newPrefix = prefix.empty() ? std::to_string(node->m) + ":" + std::to_string(node->n) : prefix;
            for (const auto& child : node->children) {
                if (child->isLeaf) {
                    std::cout << newPrefix << " --> " << child->m << "(" << child->n << ")" << std::endl;
                } else {
                    printEdges(child, newPrefix + " --> " + std::to_string(child->m) + ":" + std::to_string(child->n));
                }
            }
        }
    }

public:
    AckermannTree(int m, int n) {
        root = buildTree(m, n);
    }

    void printEdges() const {
        if (root != nullptr) {
            printEdges(root);
        }
    }
};

int main() {
    AckermannTree ackTree(1, 2);
    ackTree.printEdges();

    return 0;
}
