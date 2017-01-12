#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"

using namespace std;

int main() {
  Trie trie;

  cout << "trie.add(the)\n";
  trie.add(string("the"));
  trie.add(string("they"));
  trie.add(string("there"));
  trie.add(string("therefore"));
  cout << "trie.find(them) : " <<
  trie.checkIfExists(string("them")) << endl;
  cout << "trie.findPartially(there)\n"
    << trie.findPartially(string("there")) << endl;
  return 0;
}
