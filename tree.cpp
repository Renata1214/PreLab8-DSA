#include <iostream>
#include "tree.h"

using namespace std;

//Tree Structure
//Constructor
Node::Node (){
        root= left = right = nullptr;
        x=y=-1;
        ackerval=-10; //value of -10 to indicate the value for ackerval has not been found yet
       // allNodes++;
}

//Static variable
// int Node::allNodes =0;
int Node::idsum=0;

//Functions to create Nodes
Node* create_node (int m, int n){
    Node* mynode = new Node();
    mynode->x= m;
    mynode->y=n;
    return mynode;
}

Node* create_node_leave (int l){
    Node* mynode = new Node();
    mynode->ackerval=l;
    mynode->idsum=mynode->idsum + 1;
    mynode-> id= mynode->idsum;
    return mynode;
}

//Acker Function
Node* Node::Acker (int x, int y){
        if (x==0){
            //create_node_leave()
            ackerval=y+1;
            Node* tree_node = create_node_leave(ackerval); //new node ()
            tree_node->root= this;
            left = tree_node;
            //cout << "The ultimate value is " << ackerval << endl;
            return left;
        }

        else if (y==0){
            Node* tree_node1 = create_node(x-1,1);
            right = tree_node1;
            tree_node1->root= this;
            return tree_node1->Acker(x-1,1);
        }
        else {
            //left : Only leaves, 
            Node* tree_node2 = create_node_leave(x-1);
            tree_node2->root= this;
            left = tree_node2;
            //right
            Node* tree_node3 = create_node (x, y-1);
            tree_node3->root= this;
            right = tree_node3;

            return tree_node3->Acker(x, y-1);
        }
}

//Printing function
void print (Node* nodeval){
   
        if (nodeval->left== nullptr && nodeval->right==nullptr){
            
            return;
        }
        if (nodeval->left != nullptr){
            cout << nodeval -> x << ":" << nodeval -> y << "---> " ;
            cout << nodeval->left->id << "(" << nodeval ->left->ackerval << ") " << endl;
        }
        if (nodeval->right != nullptr){
            cout << nodeval -> x << ":" << nodeval -> y << "---> " ;
            cout << nodeval ->right-> x << ":" << nodeval->right-> y << endl;
            print (nodeval->right);
        }

}


