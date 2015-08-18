#include <iostream>
#include "stack.h"
using namespace std;

int main() {
  int i = 1; 
  Stack<int> ss;
  while(i <= 5)  {
    (ss.push(i*11));
    i++;
  }
  cout << ss.pop() << " popped from stack\n";
  cout << ss.pop() << " popped fron stack\n";
  ss.push(111);
  cout << ss;   
  
  return 0;
}
