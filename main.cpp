#include <iostream>
#include "tree.h"

using namespace std;


void delete_tree(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left!=nullptr){
        delete_tree(root->left);
    }
    if (root->right!=nullptr){
        delete_tree(root->right);
    }
    
}

int main (){
Node mynode1;
mynode1.x=3;
mynode1.y=3;
mynode1.Acker(3,3);
Node* temporal;
temporal= &mynode1;
print (temporal);

delete_tree(temporal);

return 0;
}
