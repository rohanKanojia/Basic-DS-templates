#include <unistd.h>
#include <iostream>
#include "list.h"

template <typename T>
list<T>::list(list<T>& ll) {
  head = NULL;
  Node<T> *tmp = ll.getHead();
  while(tmp) {
    insert(tmp->getElement());
    tmp = tmp->getNext();
  }
}

template <typename T>
bool list<T>::insert(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  if(head == NULL) {
    head = newNode;
  }
  else {
    Node<T> *tmp = head;
    while(tmp->getNext() != NULL) {
      tmp = tmp->getNext();
    }
    tmp->setNext(newNode);
  }
  return true;
}

template <typename T>
bool list<T>::insertBeg(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  
  newNode->setNext(head);
  head = newNode;
  return true;
}

template <typename T>
bool list<T>::insertEnd(T ee) {
  return insert(ee);
}

template <typename T>
bool list<T>::insertAfter(T ee, T after) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  Node<T> *afterNode = search(after);
  if(!afterNode) return false;
  
  newNode->setNext(afterNode->getNext());
  afterNode->setNext(newNode);
  return true;
}

template <typename T>
bool list<T>::insertBefore(T ee, T bb) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  Node<T> *before = head;
  
  if(before->getElement() == bb) {
    newNode->setNext(before);
    head = newNode;
    return true;
  }
  while(before != NULL) {
    if(before->getNext())
      if(before->getNext()->getElement() == bb)
        break;
    before = before->getNext();
  }
  if(!before) {
    std::cout << "Element not found\n";
    return false;
  }
  else {
    newNode->setNext(before->getNext());
    before->setNext(newNode);
  }
  return true;
}

template <typename T>
bool list<T>::deleteBeg() {
  if(!head) 
    return false;
  else {
    Node<T> *tmp = head;
    head = head->getNext();
    delete tmp;
    return true;
  }
}

template <typename T>
bool list<T>::deleteEnd() {
  if(!head)
    return false;
  else {
    Node<T> *curr, *prev;
    curr = head;
    prev = head;
    // Checking if only one node left
    if(head->getNext() == NULL) {
      head = head->getNext();
    }
    else {
      while(curr->getNext() != NULL) {
        prev = curr;
        curr = curr->getNext();
      }
      prev->setNext(NULL);
      delete curr;
    }
    return true;
  } 
}

template <typename T>
bool list<T>::deleteAfter(T after) {
  if(!head) 
    return false;
  Node<T> *curr, *prev;
  prev = search(after);
  if(!prev || !prev->getNext()) 
    return false;
  curr = prev->getNext();
  prev->setNext(curr->getNext());
  delete curr;
  return true;
}

template <typename T>
bool list<T>::deleteBefore(T before) {
  Node<T> *curr, *prev;
  if(!head) 
    return false;
  curr = prev = head;
  while(curr != NULL)  {
    if(curr->getNext())
      if(curr->getNext()->getElement() == before)
        break;   
    prev = curr;
    curr = curr->getNext();
  }
  if(!curr)
    return false;
  else if(curr == head) 
    head = head->getNext();
  else
    prev->setNext(curr->getNext());
  delete curr;
  return true;
}

template <typename T>
int list<T>::length() {
  Node<T> *tmp = head;
  int count = 0;
  while(tmp) {
    count++;
    tmp = tmp->getNext();
  }
  return count;
}

template <typename T>
void list<T>::traverse() {
  Node<T> *tmp = head;
  std::cout << "list :-> ";
  if(!tmp)
    std::cout << "(nil)\n";
  while(tmp) {
    std::cout << tmp->getElement();
    tmp = tmp->getNext();
    if(tmp)
      std::cout << ", ";
  }
  std::cout << "\n";
}

template <typename T> 
bool list<T>::deleteByElement(T ee) {
  if(!head) 
    return false;
  Node<T> *curr, *prev;
  curr = prev = head;
  
  while(curr != NULL && curr->getElement() != ee) {
    prev = curr;
    curr = curr->getNext();
  }
  if(!curr)
    return false;
  prev->setNext(curr->getNext());
  delete curr;
  return false;
}

template <typename T>
list<T> list<T>::reverse() {
  list<T> tmp = *this;
  if(tmp.length() > 1) {  
    Node<T> *curr, *prev, *fwd;
    curr = tmp.getHead();
    fwd = curr->getNext();
    prev = NULL;
    
    while(curr) {
      curr->setNext(prev);
      prev = curr;
      curr = fwd;
      if(fwd)
        fwd = fwd->getNext();
    }
    tmp.setHead(prev);
  }
  return tmp;
}

template <typename T>
list<T> list<T>::sort() {
  bool swapped;
  Node<T> *a, *b, *i;
  if(length() > 1) {
    do {
      swapped = false;
      for(i = getHead(); i->getNext(); i = i->getNext()) {
        a = i;
        b = i->getNext();
        if(a->getElement() > b->getElement()) {
          swapped = true;
          T tmp;
          tmp = a->getElement();
          a->setElement(b->getElement());
          b->setElement(tmp);
        }
      }
    } while(swapped == true);
  }
  return *this;
}

template <typename T>
Node<T> *list<T>::search(T element) {
  Node<T> *tmp = head;
  while(tmp) {
    if(tmp->getElement() == element)
      break;
    tmp = tmp->getNext();
  }
  return tmp;
}

template <typename T>
list<T> list<T>::operator+(list<T>& ll) {
  list<T> tmp = *this;
  Node<T> *tmp2 = ll.getHead();
  
  while(tmp2) {
    tmp.insert(tmp2->getElement());
    tmp2 = tmp2->getNext();
  } 
  return tmp;
}

template <typename T>
void list<T>::destroyList() {
  if(head) {
    Node<T> *tmp1, *tmp2;
    tmp1 = head;
  
    while(tmp1) {
      tmp2 = tmp1;
      tmp1 = tmp1->getNext();
      delete tmp2;
    }
    head = NULL;
  }
}

template <typename T>
list<T>& list<T>::operator=(const list<T>& ll) {
  destroyList();
  Node<T> *tmp;
  tmp = ll.getHead();
 
  while(tmp != NULL) {
    insert(tmp->getElement());
    tmp = tmp->getNext();
  }
  return *this;
}

template <typename T>
list<T>::~list() {
  destroyList();
}

