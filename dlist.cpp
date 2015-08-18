#include <iostream>
#include "dlist.h"

template <typename T>
dlist<T>::dlist(dlist<T>& dd) {
  head = NULL;
  Node<T> *tmp = dd.getHead();
  
  while(tmp) {
    insert(tmp->getElement());
    tmp = tmp->getFwd();
  }
}

template <typename T>
bool dlist<T>::insert(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  
  if(!head) {
    head = newNode;
  }
  else {
    Node<T> *tmp = head;
    while(tmp->getFwd()) 
      tmp = tmp->getFwd();
    tmp->setFwd(newNode);
    newNode->setBack(tmp);
  }
  return true;
}

template <typename T>
bool dlist<T>::insertEnd(T ee) {
  return insert(ee);
}

template <typename T>
bool dlist<T>::insertBeg(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  
  if(!head) {
    head = newNode;
  }
  else {
    head->setBack(newNode);
    newNode->setFwd(head);
    head = newNode;
  }
  return true;
}

template <typename T>
bool dlist<T>::insertAfter(T ee, T after) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  Node<T> *afterNode = search(after);
  if(!afterNode) return false;
  else if(!afterNode->getFwd()) {
    afterNode->setFwd(newNode);
    newNode->setBack(afterNode);
  }
  else { 
    newNode->setFwd(afterNode->getFwd());
    newNode->setBack(afterNode);
    afterNode->getFwd()->setBack(newNode);
    afterNode->setFwd(newNode);
  }
  return true;
}

template <typename T>
bool dlist<T>::insertBefore(T ee, T before) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  Node<T> *beforeNode = search(before);
  if(!beforeNode) return false;
 
  if(beforeNode == head) {
    head->setBack(newNode);
    newNode->setFwd(head);
    head = newNode;
  }
  else { 
    newNode->setBack(beforeNode->getBack());
    newNode->setFwd(beforeNode);
    beforeNode->getBack()->setFwd(newNode);
    beforeNode->setBack(newNode);
  }
  return true;
}

template <typename T>
Node<T> *dlist<T>::search(T target) {
  Node<T> *tmp = head;
  while(tmp) {
    if(tmp->getElement() == target) 
      break;
    tmp = tmp->getFwd();
  }
  return tmp;
}

template <typename T>
int dlist<T>::length() {
  Node<T> *tmp = head;
  int count = 0;
  while(tmp) {
    count++;
    tmp = tmp->getFwd();
  }
  return count;
}

template <typename T>
void dlist<T>::traverseFwd() {
  Node<T> *tmp = head;
  std::cout << "list [->] ";
  if(!tmp) std::cout << "(nil)\n";

  while(tmp) {
    std::cout << tmp->getElement() ;
    tmp = tmp->getFwd();
    if(tmp) 
      std::cout << ", ";
  }
  std::cout << "\n";
}

template <typename T>
void dlist<T>::traverseBack() {
  Node<T> *tmp = head;
  std::cout << "list [<-]: ";
  int cnt = 0;
  if(!tmp) std::cout << "(nil)\n";
  else { 
    while(tmp->getFwd()) 
      tmp = tmp->getFwd();
    while(tmp) {
      std::cout << tmp->getElement();
      tmp = tmp->getBack();
      if(tmp) 
        std::cout << ", ";
      cnt++;
    }
    std::cout << "\n";
  }
}

template <typename T>
bool dlist<T>::deleteBeg() {
  if(!head)
    return false;
  Node<T> *tmp = head;
  head = head->getFwd();
  if(head)
    head->setBack(NULL);
  delete tmp;
  return true;
}

template <typename T>
bool dlist<T>::deleteEnd() {
  if(!head)
    return false;
  Node<T> *tmp = head;
  if(length() == 1) {
    head = NULL;
  }
  else {
    while(tmp->getFwd()) 
      tmp = tmp->getFwd();
    tmp->getBack()->setFwd(NULL);
  }
  delete tmp;
  return true;
}

template <typename T>
bool dlist<T>::deleteAfter(T after) {
  Node<T> *tmp, *afterNode;
  afterNode = search(after);
  if(!afterNode)
    return false;
  tmp = afterNode->getFwd();
  if(!tmp) return false;
  afterNode->setFwd(tmp->getFwd());
  if(tmp->getFwd())
    tmp->getFwd()->setBack(afterNode);
  delete tmp;
  return true;
}

template <typename T>
bool dlist<T>::deleteBefore(T before) {
  Node<T> *tmp, *beforeNode;
  beforeNode = search(before);
  if(!beforeNode)
    return false;
  tmp = beforeNode->getBack();
  if(!tmp) return false;
  else if(tmp == head) {
    head = head->getFwd();
    head->setBack(NULL);
  }
  else {
    tmp->getBack()->setFwd(beforeNode);
    beforeNode->setBack(tmp->getBack());
  }
  delete tmp;
  return true;
}

template <typename T>
bool dlist<T>::deleteByElement(T element) {
  Node<T> *tmp = search(element);
  if(!tmp)
    return false;
  if(tmp == head) {
    head = head->getFwd();
    head->setBack(NULL);
  }
  else {
    tmp->getBack()->setFwd(tmp->getFwd());
    tmp->getFwd()->setBack(tmp->getBack());
  }
  delete tmp;
  return true;
}

template <typename T>
Node<T> *dlist<T>::getHead() const {
  return head;
}

template <typename T>
void dlist<T>::setHead(Node<T> *hh) {
  head = hh;
}

template <typename T>
dlist<T>& dlist<T>::sort() {
  Node<T> *a, *b, *i;
  bool swapped;
  do {
    swapped = false;
    for(i = head; i->getFwd(); i = i->getFwd()) {
      a = i;
      b = i->getFwd();
      if(a->getElement() > b->getElement()) {
        swapped = true;
        T tmp = a->getElement();
        a->setElement(b->getElement());
        b->setElement(tmp);
      }
    }
  } while(swapped == true);  
  return *this;
}

template <typename T>
dlist<T>& dlist<T>::reverse() {
  Node<T> *tmp = head, *curr = NULL;
  while(tmp->getFwd()) {
    curr = tmp;
    tmp = tmp->getFwd();  
    curr->swapLinks();
  }
  tmp->swapLinks();
  head = tmp;
  return *this;
}

template <typename T>
void dlist<T>::destroyList() {
  if(head) {
    Node<T> *tmp = head, *curr;
    while(tmp) {
      curr = tmp;
      tmp = tmp->getFwd();
      delete curr;
    }
    head = NULL;
  }
}

template <typename T>
dlist<T>::~dlist() {
  destroyList();
}

template <typename T>
dlist<T>& dlist<T>::operator=(const dlist<T>& dd) {
  destroyList();
  Node<T> *tmp;
  tmp = dd.getHead();
  
  while(tmp) {
    insert(tmp->getElement());
    tmp = tmp->getFwd();
  }
  return *this;
}

template <typename T>
dlist<T> dlist<T>::operator+(dlist<T>& dd) {
  dlist<T> newList = *this;
  Node<T> *tmp = dd.getHead();
  
  while(tmp) {
    newList.insert(tmp->getElement());
    tmp = tmp->getFwd();
  }
  return newList;
}

template <typename T>
void dlist<T>::traverse() {
  traverseFwd();
  traverseBack();
} 
