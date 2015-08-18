#ifndef SET_H
#define SET_H
template <typename T>
class SetNode {
  T elem;
  SetNode *next;
public:
  SetNode() {
    next = NULL;
  }
  SetNode(T ee, SetNode *nn=NULL) {
    elem = ee;
    next = nn;
  }
  T getElement() {
    return elem;
  }
  SetNode *getNext() {
    return next;
  }
  void setElement(T ee) {
    elem = ee;
  }
  void setNext(SetNode *nn) {
    next = nn;
  }
};

template <typename T>
class Set {
  SetNode<T> *head;
public:
  Set() {
    head = NULL;
  }
  bool add(T ee) {
    if(search(ee))
      return false;
    SetNode<T> *newNode = new SetNode<T>(ee);
    if(!newNode)
      return false;
    if(!head) 
      head = newNode;
    else {
      SetNode<T> *curNode = head;
      while(curNode->getNext())
        curNode = curNode->getNext();
      curNode->setNext(newNode);
    }
    return true;
  }
  T remove() {
    if(!head) 
      return T(0);
    else {
      SetNode<T> *curr = head, *prev= NULL;
      while(curr->getNext()) {
        prev = curr;
        curr = curr->getNext();
      }
      prev->setNext(curr->getNext());
      T tmp = curr->getElement();
      delete curr;
      return tmp;
    }
  }
  SetNode<T> *search(T elem) {
    SetNode<T> *curNode = head;
    
    while(curNode) {
      if(curNode->getElement() == elem) 
        break;
      curNode = curNode->getNext();
    }
    return curNode;
  }
  T operator[](int index) {
    SetNode<T> *curNode = head;
    int count = 0;
    
    if(index < 0)
      return T(0);
    while(count < index && curNode) {
      curNode = curNode->getNext();
      count++;
    }
    return curNode ? curNode->getElement() : NULL;
  }
};
#endif
