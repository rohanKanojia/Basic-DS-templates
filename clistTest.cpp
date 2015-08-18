#include <iostream>
#include "clist.h"

using namespace std;

int main() {
  clist<int> cc;
  int i = 1;
  cout << "Entering insertion...\n";
  while(i <= 5) {
    if(cc.insert(i*10+i) == true)
      cout << i*10+i << " inserted into circular linked list\n";
    i++;
  }                                  

  clist<int> dd;
  dd.insert(1010);
  dd.insert(100100);
  cc.traverse();
  cout << "=======================================\n";

  cc = dd + cc;
  cout << "calling traverse\n"; 

  cc.traverse();  
  return -1;
}
