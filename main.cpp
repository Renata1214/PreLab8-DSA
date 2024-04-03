#include <iostream>
#include "tree.h"

using namespace std;


int main (){

Node mynode1;
mynode1.x=1;
mynode1.y=2;
mynode1.Acker(1,2);
Node* temporal;
temporal= &mynode1;
print (temporal);

return 0;

}
