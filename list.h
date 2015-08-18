#ifndef LIST_H
#define LIST_H
template<typename T>
class Node {
  T element;
  Node<T> *next;
public:
  Node() : next(NULL) { }
  Node(T ee, Node<T> *nn = NULL) : element(ee), next(nn) { }
  T getElement() const { 
    return element;
  }
  Node<T> *getNext() const {
    return next;
  }
  void setElement(T ee) {
    element = ee;
  }
  void setNext(Node<T> *nn) {
    next = nn;
  }
};

template<typename T>
class list {
  Node<T> *head;
public:
  list() : head(NULL) { }
  list(list<T>& ll);
  Node<T> *getHead() const { 
    return head;
  }
  void setHead(Node<T> *hh) {
    head = hh;
  }
  bool insert(T ee);
  bool insertBeg(T ee);
  bool insertEnd(T ee);
  bool insertAfter(T ee, T after);
  bool insertBefore(T ee, T before);
  bool deleteBeg();
  bool deleteEnd();
  bool deleteAfter(T after);
  bool deleteBefore(T before);  
  bool deleteByElement(T elem);
  int length();
  list<T> reverse();
  list<T> operator+(list<T>& ll);
  list<T>& operator=(const list<T>& ll);
  list<T> sort();
  Node<T> *search(T target);
  void traverse();
  void destroyList();
  ~list();
};

#include "list.cpp"
#endif
