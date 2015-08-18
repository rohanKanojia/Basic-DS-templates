#include <iostream>
#include "clist.h"

template <typename T>
clist<T>::clist(clist& cc) {
  head = NULL;
  Node<T> *tmp = cc.getHead();
  do {
    insert(tmp->getElement());
    tmp = tmp->getNext();
  } while(tmp != cc.getHead());
}

template <typename T>
bool clist<T>::insert(T ee) {
  Node<T> *newNode = new Node<T>(ee), *tmp;
  if(!newNode) return false;
  if(!head) {
    head = newNode;
    head->setNext(newNode);
  }
  else {
    Node<T> *tmp = head->getNext();
    while(tmp->getNext() != head) 
      tmp = tmp->getNext();
    tmp->setNext(newNode);
    newNode->setNext(head);
  }
  return true;
}

template <typename T>
bool clist<T>::insertBeg(T ee) {
  Node<T> *newNode = new Node<T>(ee);
  if(!newNode) return false;
  else if(!head) {
    head = newNode;
    newNode->setNext(head);
  }
  else {
    Node<T> *tmp = head;
    do {
      tmp = tmp->getNext();
    } while(tmp->getNext() != head);
    tmp->setNext(newNode);
    newNode->setNext(head);
    head = newNode;
  }
  return true;
}

template <typename T>
bool clist<T>::insertEnd(T ee) {
  return insert(ee);
}

template <typename T>
bool clist<T>::insertAfter(T ee, T after) {
  Node<T> *aNode, *newNode;
  aNode = search(after);
  if(!aNode) return false;
  newNode = new Node<T>(ee);
  if(!newNode) return false;
  
  newNode->setNext(aNode->getNext());
  aNode->setNext(newNode);
  return true;
}

template <typename T>
bool clist<T>::insertBefore(T ee, T before) {
  Node<T> *tmp, *newNode, *bNode = search(before);
  newNode = new Node<T>(ee);
  if(!newNode || !bNode) return false;
  else if(bNode == head) {
    tmp = head;
    do {
      tmp = tmp->getNext();
    } while(tmp->getNext() != head);
    tmp->setNext(newNode);
    newNode->setNext(head);
    head = newNode;     
  }
  else { 
    tmp = head->getNext();
    while(tmp) {
      if(tmp->getNext()->getElement() == before)
        break;
      tmp = tmp->getNext();
    }
    if(!tmp) return false;
    newNode->setNext(tmp->getNext());
    tmp->setNext(newNode);
  }
  return true;
} 

template <typename T>
Node<T> *clist<T>::search(T elem) {
  if(!head) return NULL;
  Node<T> *tmp = head;
  int attempts = 0;
  
  do {
    if(tmp->getElement() == elem) 
      break;
    tmp = tmp->getNext();
    attempts++;
  } while(tmp != head);
  if(attempts == length())
    return NULL;
  else 
    return tmp;
}

template <typename T>
bool clist<T>::deleteBeg() {
  Node<T> *toDelete, *tmp;
  if(!head) return false;
  else if(length() == 1) {
    toDelete = head;
    head = NULL;
  }    
  else {
    tmp = head->getNext();
    while(tmp->getNext() != head) 
      tmp = tmp->getNext();    
    tmp->setNext(head->getNext());
    toDelete = head;
    head = head->getNext();
  }
  delete toDelete;
  return true;
}    

template <typename T>
bool clist<T>::deleteEnd() {
  Node<T> *tmp, *toDelete;
  if(!head) return false;
  else if(length() == 1) {
    toDelete = head;
    head = NULL;
  }
  else {
    toDelete = head->getNext();
    while(toDelete->getNext() != head) { 
      tmp = toDelete;
      toDelete = toDelete->getNext();
    }
    tmp->setNext(head);
  }
  delete toDelete;
  return true;
}

template <typename T>
bool clist<T>::deleteAfter(T after) {
  Node<T> *aNode = search(after), *toDelete;
  if(!head || !aNode) return false;
  else {
    toDelete = aNode->getNext();
    if(toDelete == head) return false;
    aNode->setNext(toDelete->getNext());
  }
  delete toDelete;
  return true;
}

template <typename T>
bool clist<T>::deleteBefore(T before) {
  Node<T> *bNode = search(before), *toDelete, *pre, *curr;
  if(!head || !bNode || bNode == head) return false;
  else if(head->getNext() == bNode) {
    // Deleting head
    curr = toDelete = head;
    while(curr->getNext() != head)
      curr = curr->getNext();
    curr->setNext(head->getNext());
    head = head->getNext();
  }
  else {
    curr = head->getNext(); 
    while(curr->getNext() != bNode) {
      pre = curr;
      curr = curr->getNext();
    }
    pre->setNext(curr->getNext());
    toDelete = curr;
  }
  delete toDelete;
  return true;
}  
      
template <typename T>
void clist<T>::traverse() {
  std::cout << "List :";
  Node<T> *tmp = head;
  if(!head) 
    std::cout << "(nil)\n";
  else {
    do {
      std::cout << tmp->getElement() << " ";
      tmp = tmp->getNext();
    } while(tmp != head);
    std::cout << "\n";
  }
}

template <typename T>
int clist<T>::length() {
  if(!head) return 0;
  else {
    Node<T> *tmp = head->getNext();
    int count = 1;
    while(tmp != head) {
      tmp = tmp->getNext();
      count++;
    }
    return count;
  }
}

template <typename T>
clist<T>& clist<T>::operator=(const clist& cc) {
  destroyList();
  Node<T> *tmp = cc.getHead();
  
  if(tmp) {
    do {
      insert(tmp->getElement());
      tmp = tmp->getNext();
    } while(tmp != cc.getHead());
  }
  return *this;
}

template <typename T>
clist<T> clist<T>::operator+(clist& cc) {
  Node<T> *tmp = cc.getHead();
  clist<T> nlist = *this;
  
  nlist.insert(tmp->getElement());
  tmp = tmp->getNext();
  while(tmp != cc.getHead()) {
    nlist.insert(tmp->getElement());
    tmp = tmp->getNext();
  }
  return nlist;
}

template <typename T>
clist<T>& clist<T>::sort() {
  Node<T> *a, *b, *i;
  bool swapped = true;
  if(length() > 1) {
    do {
      swapped = false;
      for(i =head->getNext();i->getNext() != head;i = i->getNext()) {
        a = i;
        b = i->getNext();
        if(a->getElement() > b->getElement()) {
          T tmp = a->getElement();
          a->setElement(b->getElement());
          b->setElement(tmp);
        }
      }
    } while(swapped == true);
  }
  return *this;
}

template <typename T>
clist<T>& clist<T>::reverse() {
  if(length() > 1) {
    Node<T> *curr, *prev, *fwd;
    // Finding head
    prev = head->getNext();      
    while(prev->getNext() != head) 
      prev = prev->getNext();

    curr = head;
    fwd = head->getNext();    
    do {
      curr->setNext(prev);
      prev = curr;
      curr = fwd;
      fwd = fwd->getNext();
    } while(curr != head);
    head = prev;
  }
  return *this;
}

template <typename T>
void clist<T>::destroyList() {
  if(head) {
    Node<T> *tmp = head, *curr;
    do {
      curr = tmp;
      tmp = tmp->getNext();
      delete curr;
    } while(tmp != head);
    head = NULL;
  }
}

template <typename T>
clist<T>::~clist() {
  destroyList();
}

template <typename T>
bool clist<T>::deleteByElement(T elem) {
  Node<T> *toDelete = search(elem), *prev = NULL;
  if(!head || !toDelete)
    return false;
  else if(head == toDelete && length() > 1) {
    Node<T> *tmp = head;
    do {
      tmp = tmp->getNext();
    } while(tmp->getNext() != head);
    tmp->setNext(head->getNext());
    toDelete = head;
    head = head->getNext();
  }
  else if(head == toDelete && length() == 1) {
    toDelete = head;
    head = NULL;
  }
  else {
    prev = head;
    do {
      if(prev->getNext() == toDelete)
        break;
      prev = prev->getNext();
    } while(prev != head);
    prev->setNext(toDelete->getNext()); 
  }
  delete toDelete;
  return true;
}     
