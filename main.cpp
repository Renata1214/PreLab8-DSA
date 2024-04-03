#include <iostream>
#include "tree.h"

using namespace std;


int main (){

Node mynode1;

mynode1.Acker(2,3);

Node* temporal;
temporal= &mynode1;

while (temporal->ackerval==-10){
    if (temporal->right != nullptr){
        temporal = temporal->right;
        cout << temporal -> x << " , " << temporal -> y << endl;
    }
    else {
        break;
    }
}

cout << temporal->ackerval << endl;

return 0;

}