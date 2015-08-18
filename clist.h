#ifndef CLIST_H
#define CLIST_H

template <typename T>
class Node {
  T element;
  Node *next;
public:
  Node() : next(NULL) { }
  Node(T ee, Node *nn = NULL) : element(ee), next(nn) { }
  T getElement() {
    return element;
  }
  Node *getNext() {
    return next;
  }
  void setElement(T elem) {
    element = elem;
  }
  void setNext(Node *nn) {
    next = nn;
  }
};

template <typename T>
class clist {
  Node<T> *head;
public:
  clist() : head(NULL) { }
  clist(clist& cc);
  Node<T> *getHead() const {
    return head;
  }
  void setHead(Node<T>* hh) {
    head = hh;
  }
  bool insert(T ee);
  bool insertBeg(T ee);
  bool insertEnd(T ee);
  bool insertAfter(T ee, T af);
  bool insertBefore(T ee, T before);
  bool deleteEnd();
  bool deleteAfter(T after);
  bool deleteBefore(T before);
  bool deleteByElement(T elem);
  bool deleteBeg();
  void traverse();
  int length();
  Node<T> *search(T target);
  clist& operator=(const clist& cc);
  clist operator+(clist& cc);
  ~clist();
  clist& sort();
  clist& reverse();
  void destroyList();
};
#include "clist.cpp"
#endif
