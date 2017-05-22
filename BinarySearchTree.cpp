#include <iostream>
#include "BinarySearchTree.h"

template <typename T>
bool BinarySearchTree<T>::insert(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  if(!root) 
    root = newNode;
  else 
    searchAndInsert(root, newNode);
  return true;
}

template <typename T>
void BinarySearchTree<T>::searchAndInsert(Node<T> *curNode, Node<T> *newNode) {
  if(curNode->getElement() > newNode->getElement()) {
    if(!curNode->getLeft())
      curNode->setLeft(newNode);
    else 
      searchAndInsert(curNode->getLeft(), newNode);
  }
  else {
    if(!curNode->getRight())
      curNode->setRight(newNode);
    else 
      searchAndInsert(curNode->getRight(), newNode);
  }
}

template <typename T>
void BinarySearchTree<T>::traversePreorder() {
  std::cout << "Tree Preorder traversal: ";
  if(!root) 
    std::cout << "(nil)";
  traversePreorder(root);
  std::cout << "\n";
}

template <typename T>
void  BinarySearchTree<T>::traversePreorder(Node<T> *curNode) {
  if(curNode) {
    std::cout << " " << curNode->getElement();
    traversePreorder(curNode->getLeft());
    traversePreorder(curNode->getRight());
  }
}

template <typename T>
void BinarySearchTree<T>::traverseInorder() {
  std::cout << "Tree Inorder traversal: ";
  if(!root) 
    std::cout << "(nil)";
  traverseInorder(root);
  std::cout << "\n";  
}

template <typename T>
void BinarySearchTree<T>::traverseInorder(Node<T> *curNode) {
  if(curNode) {
    traverseInorder(curNode->getLeft());
    std::cout << " " << curNode->getElement();
    traverseInorder(curNode->getRight());
  }
}

template <typename T>
void BinarySearchTree<T>::traversePostorder() {
  std::cout << "Tree Postorder traversal: ";
  if(!root) 
    std::cout << "(nil)";
  traversePostorder(root);
  std::cout << "\n";
}

template <typename T>
void BinarySearchTree<T>::traversePostorder(Node<T> *curNode) {
  if(curNode) {
    traversePostorder(curNode->getLeft());
    traversePostorder(curNode->getRight());
    std::cout << " " << curNode->getElement();
  }
}

template <typename T>
Node<T> *BinarySearchTree<T>::search(T elem) {
  Node<T> *curNode = root;
  
  while(curNode) {
    if(curNode->getElement() == elem)
      break;
    else if(curNode->getElement() > elem) 
      curNode = curNode->getLeft();
    else 
      curNode = curNode->getRight();
  }
  return curNode;
}


template <typename T>
int BinarySearchTree<T>::depth() {
  return depth(root);
}

template <typename T>
int BinarySearchTree<T>::depth(Node<T> *curNode) {
  int leftDepth, rightDepth;
  if(!curNode)
    return 0;
  leftDepth = depth(curNode->getLeft());
  rightDepth = depth(curNode->getRight());
  
  return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

template <typename T>
Node<T> *BinarySearchTree<T>::searchParent(T elem) {
  Node<T> *parent = NULL, *curNode = root;
  while(curNode) {
    if(curNode->getElement() == elem)
      break;
    else if(curNode->getElement() > elem) { 
      parent = curNode;
      curNode = curNode->getLeft();
    }
    else {
      parent = curNode;
      curNode = curNode->getRight();
    }
  }
  return parent;
}

template <typename T>
bool BinarySearchTree<T>::deleteNode(T elem) {
  Node<T> *toDelete, *toDeletePar;
  toDelete = search(elem);
  if(!toDelete)
    return false;
  toDeletePar = searchParent(elem);
  
  if(toDelete->getRight() && toDelete->getLeft())
    removeNodeTwoChildren(toDelete, toDeletePar);
  else
    removeNode(toDelete, toDeletePar);
  delete toDelete;
  return true;
}

template <typename T>
void BinarySearchTree<T>::removeNode(Node<T> *curNode, Node<T> *par) {
  Node<T> *child;
  // Initializing the child
  if(!curNode->getLeft() && !curNode->getRight())
    child = NULL;
  else if(curNode->getLeft())
    child = curNode->getLeft();
  else 
    child = curNode->getRight();
  
  // Setting parent node
  if(par != NULL) {
    if(par->getLeft() == curNode)
      par->setLeft(child);
    else 
      par->setRight(child);
  }
  else 
    root = child;
}

template <typename T>
void BinarySearchTree<T>::removeNodeTwoChildren(Node<T> *curNode, Node<T> *par) {
  Node<T> *suc = curNode->getRight(), *parSuc = curNode;

  // Find inorder successor  
  while(suc->getLeft()) {
    parSuc = suc;
    suc = suc->getLeft();
  }
  
  // Remove inorder successor from tree
  removeNode(suc, parSuc);
  // Replace node with it's inorder successor
  if(par) {
    if(par->getLeft() == curNode)
      par->setLeft(suc);
    else 
      par->setRight(suc);
  }
  else 
    root = suc;
  suc->setRight(curNode->getRight());
  suc->setLeft(curNode->getLeft());
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& bb) {
  root = NULL;
  Node<T> *curNode = bb.getRoot();
  
  copyTree(curNode);
}

template <typename T>
void BinarySearchTree<T>::copyTree(Node<T> *curNode) {
  if(curNode) {
    insert(curNode->getElement());
    copyTree(curNode->getLeft());
    copyTree(curNode->getRight());
  }
}

template <typename T>
void BinarySearchTree<T>::destroyTree() {
  while(root) 
    deleteNode(root->getElement());
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree& bb) {
  destroyTree();
  Node<T> *curNode = bb.getRoot();
  
  copyTree(curNode);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  destroyTree();
}

template <typename T>
BinarySearchTree<T> BinarySearchTree<T>::createMirror() {
  BinarySearchTree<T> tt = *this;
  
  tt.swapChildren(tt.getRoot());
  return tt;
}

template <typename T>
void BinarySearchTree<T>::swapChildren(Node<T> *curNode) {
  if(curNode) {
    swapChildren(curNode->getLeft());
    swapChildren(curNode->getRight());
    Node<T> *tmp = curNode->getLeft();
    curNode->setLeft(curNode->getRight());
    curNode->setRight(tmp);
  }
}

template <typename T>
Node<T> *BinarySearchTree<T>::lowestcommonAncestor(T e1, T e2) {
  if(!search(e1) || !search(e2))
    return NULL;
  Node<T> *curNode = root;
  while(curNode) {
    if(curNode->getElement() > e1 && curNode->getElement() > e2)
      curNode = curNode->getLeft();
    else if(curNode->getElement()<e1 && curNode->getElement()<e2)
      curNode = curNode->getRight();
    else 
      break;
  }
  return curNode;
}

template <typename T>
int BinarySearchTree<T>::getDiameter() {
  int diameter = 0;
  getDiameterUtil(root, diameter);
  return diameter;
}

template <typename T>
int BinarySearchTree<T>::getDiameterUtil(Node<T> *curNode, int& diameter) {
  int nLeft, nRight;
  if(!curNode)
    return 0;
  nLeft = getDiameterUtil(curNode->getLeft(), diameter);
  nRight = getDiameterUtil(curNode->getRight(), diameter);
  
  if(nLeft + nRight > diameter)
    diameter = nLeft + nRight+1;
  return std::max(nLeft, nRight) + 1;
}
