#include <iostream>
#include "BinarySearchTree.h"

int main() {
  BinarySearchTree<char> bb;
  bb.insert('o');
  bb.insert('d');
  bb.insert('c');
  bb.insert('f');
  bb.insert('s');
  bb.insert('p');
  bb.insert('r');
  bb.insert('z');
  
  bb.traversePreorder();
  bb.traverseInorder();
  bb.traversePostorder();
  std::cout << "lowest common ancestor of 'z' and 'p' is " 
            << bb.lowestcommonAncestor('z', 'p')->getElement() 
            << "\n";
  BinarySearchTree<char> cc = bb.createMirror();
  std::cout << "Mirror created ...\n";
  std::cout << "Mirror :------------------------------->\n";
  cc.traversePreorder();
  return 0;
}
