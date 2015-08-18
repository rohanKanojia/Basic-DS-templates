#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class QueueNode {
  T elem;
  QueueNode *next;
public:
  QueueNode() { 
    next = NULL;
  }
  QueueNode(T ee, QueueNode *nn=NULL) {
    elem = ee;
    next = nn;
  }
  T getElement() {
    return elem;
  }
  QueueNode *getNext() {
    return next;
  }
  void setElement(T ee) {
    elem = ee;
  }
  void setNext(QueueNode *nn) {
    next = nn;
  }
};

template <typename T>
class Queue {
  QueueNode<T> *head;
public:
  Queue() : head(NULL) { }
  Queue(const Queue& qq) {
    head = NULL;
    QueueNode<T> *curNode = getHead();
    
    while(curNode) {
      add(curNode->getElement());
      curNode = curNode->getNext();
    }
  }    
  QueueNode<T> *getHead() const {
    return head;
  }
  bool add(T elem) {
    QueueNode<T> *newNode = new QueueNode<T>(elem);
    if(!newNode) return false;
    newNode->setNext(head);
    head = newNode; 
    return true;
  }
  T remove() { 
    if(!head) {
      return T(0);
    }
    else {
      QueueNode<T> *toDelete = head, *prev = NULL;
      while(toDelete->getNext()) {
        prev = toDelete;
        toDelete = toDelete->getNext();      
      }
      if(!prev) 
        head = NULL;
      else 
        prev->setNext(NULL);
      T tmp = toDelete->getElement();
      delete toDelete;
      return tmp;
    }
  }
  int size() {
    int cnt = 0;
    QueueNode<T> *curNode = head;
    
    while(curNode) {
      cnt++;
      curNode = curNode->getNext();
    }
    return cnt;
  }
  ~Queue() {
    while(head) 
      remove();
  }
};

#endif
