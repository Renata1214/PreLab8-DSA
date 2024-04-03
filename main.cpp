#include <iostream>
#include "tree.h"

using namespace std;


int main (){

Node mynode1;

mynode1.Acker(2,3);

Node* temporal;
temporal= &mynode1;

while (temporal->ackerval==-10){
    temporal = temporal->right;
}

cout << mynode1.ackerval << endl;

return 0;

}