#include <iostream>
#include <cmath>
#pragma once 

using namespace std;

//Tree Structure
struct Node {
    //Members
    int x;
    int y;
    int ackerval;
    static int allNodes;
    Node * left;
    Node * right;
    Node * root;
    //Constructor
    Node ();
    //Acker Function
    Node* Acker (int x, int y);
};

//Functions to create Nodes
Node* create_node (int m, int n);
Node* create_node_leave (int l);