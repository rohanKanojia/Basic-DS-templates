#include <iostream>
#include "minHeap.h"
using namespace std;

int main() {
  MinHeap<int> hh;

  hh.add(5);
  hh.add(6);
  hh.add(7);
  hh.add(8);
  cout << "heap head " <<
          hh.peek() << endl;
  hh.add(1);
  cout << "heap head " << 
          hh.peek() << endl;
  hh.add(3);
  cout << "deleting " <<
          hh.poll() << endl;

  cout << "heap head " <<
          hh.peek() << endl;

  return 0;
}
