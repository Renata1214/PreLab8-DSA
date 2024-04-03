#include <iostream>
#include "tree.h"

using namespace std;


int main (){

Node mynode1;

mynode1.Acker(1,2);

Node* temporal;
temporal= &mynode1;

while (temporal->ackerval==-10){
    if (temporal->right != nullptr){
        temporal = temporal->right;
        cout <<"intermediate step " << temporal -> x << " , " << temporal -> y << endl;
        cout << "acker myval "<< temporal -> left -> ackerval<< endl;
    }
    else {
         temporal = temporal->left;
         cout << "trial " << temporal -> ackerval << endl;
         break;
    }
}

cout << temporal->ackerval << endl;

return 0;

}