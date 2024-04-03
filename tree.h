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
    static int allNodes; // value just to count that the number of nodes i get are the correct ones
    Node * left;
    Node * right;
    Node * root; //Root or parent
    //Constructor
    Node ();
    //Acker Function
    Node* Acker (int x, int y);
};

//Functions to create Nodes
Node* create_node (int m, int n);
Node* create_node_leave (int l);
void print (Node * nodeval);