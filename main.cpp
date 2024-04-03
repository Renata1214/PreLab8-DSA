#include <iostream>
#include "tree.h"

using namespace std;

int main (){
Node mynode1;
mynode1.x=3;
mynode1.y=3;
mynode1.Acker(3,3);
Node* temporal;
temporal= &mynode1;
print (temporal);
return 0;
}
