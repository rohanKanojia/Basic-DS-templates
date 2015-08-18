#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

int main() {
  dlist<int> dc;
  dc.insert(12);
  dc.insert(122);
  dc.insert(1222);
  dc.insert(12222);
  dc.insert(122222);

  dlist<int> dc1;
  dc1.insert(101);
  dc1.insert(10101);
  dc1.insert(1010101);
  dc1.deleteBefore(101); 
  
  dc = dc1 + dc;

  dc.insertAfter(1, 122222);
  dc.traverseFwd();
  return 0;
}
