#ifndef DLIST_H
#define DLIST_H

template <typename T>
class Node {
  T element;
  Node *fwd;
  Node *back;
public:
  Node() {
    fwd = back = NULL;
  }
  Node(T ee, Node *f = NULL, Node *b = NULL) {
    element = ee;
    fwd = f;
    back = b;
  }
  T getElement() {
    return element;
  }
  Node *getFwd() {
    return fwd;
  }
  Node *getBack() {
    return back;
  }
  void setElement(T ee) {
    element = ee;
  }
  void setFwd(Node *f) {
    fwd = f;
  }
  void setBack(Node *b) {
    back = b;
  }
  void swapLinks() {
    Node<T> *tmp = fwd;
    fwd = back;
    back = tmp;
  }
};

template <typename T>
class dlist {
  Node<T> *head;
public:
  dlist() : head(NULL) { }
  dlist(dlist& dd);
  ~dlist();
  Node<T> *getHead() const;
  void setHead(Node<T> *hh);
  bool insert(T ee);
  bool insertAfter(T ee, T after);
  bool insertEnd(T ee);
  bool insertBeg(T ee);
  bool insertBefore(T ee, T before);
  bool deleteBeg();
  bool deleteEnd();
  bool deleteAfter(T after);
  bool deleteBefore(T before);
  bool deleteByElement(T elem);
  Node<T> *search(T target);
  dlist<T>& operator=(const dlist<T>& dd);
  dlist<T> operator+(dlist<T>& dd);
  void traverseFwd();
  void traverseBack();
  int length();
  dlist<T>& sort();
  dlist<T>& reverse();
  void destroyList();
  void traverse();  
};

#include "dlist.cpp"
#endif  
