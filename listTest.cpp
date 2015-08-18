#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main() {
  list<string> intList;
  intList.insert("Rohan");
  intList.insert("Genius");
  intList.insert("Bheema");
  intList.insert("Rita Ora");
  intList.insert("eyes");
  intList.traverse();
  intList.deleteBefore("Genius");
  intList.traverse();
  std::cout << "Deleting list\n";
  intList.traverse();

  list<string> foeList;
  foeList.insert("Prashant");
  foeList.insert("Sudhanshu");
  foeList.insert("Alix");
  foeList.insertAfter("Pumba", "Alix");
  
  intList = foeList + intList;
  intList.traverse();
  return 0;
}
