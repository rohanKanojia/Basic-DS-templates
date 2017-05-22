#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename T>
class Node {
  T element;
  Node *left;
  Node *right;
public:
  Node(T ee, Node *ll=NULL, Node *rr=NULL) {
    element = ee;
    left = ll;
    right = rr;
  }
  T getElement() {
    return element;
  }
  Node *getLeft() {
    return left;
  }
  Node *getRight() {
    return right;
  }
  void setLeft(Node *ll) {
    left = ll;
  }
  void setRight(Node *rr) {
    right = rr;
  }
};

template <typename T>
class BinarySearchTree {
  Node<T> *root;
public:
  BinarySearchTree() {
    root = NULL;
  }
  Node<T> *getRoot() const {
    return root;
  }
  BinarySearchTree(const BinarySearchTree& bst);
  bool insert(T ee);
  void searchAndInsert(Node<T> *curNode, Node<T> *newNode);
  void traversePreorder();
  void traversePreorder(Node<T> *curNode);
  void traversePostorder();
  void traversePostorder(Node<T> *curNode);
  void traverseInorder();
  void traverseInorder(Node<T> *curNode);
  Node<T> *search(T ee);
  Node<T> *searchParent(T ee);
  int depth();
  int depth(Node<T> *curNode);
  bool deleteNode(T ee);
  void removeNode(Node<T> *curNode, Node<T> *parent);
  void removeNodeTwoChildren(Node<T> *curNode, Node<T> *parent);
  BinarySearchTree& operator=(BinarySearchTree& bst);
  BinarySearchTree createMirror();
  ~BinarySearchTree();
  void destroyTree();
  void copyTree(Node<T> *curNode);
  void swapChildren(Node<T> *curNode);
  int getDiameter();
  int getDiameterUtil(Node<T> *curNode, int& diameter);
  Node<T> *lowestcommonAncestor(T e1, T e2);
};

#include "BinarySearchTree.cpp"
#endif
