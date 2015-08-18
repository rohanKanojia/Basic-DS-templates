#ifndef STACK_H
#define STACK_H

template <typename T>
class Node {
  T element;
  Node *next;
public:
  Node() : next(NULL) { }
  Node(T elem, Node *nn=NULL) : element(elem), next(nn) { }
  T getElement() {
    return element;
  }
  Node *getNext() {
    return next;
  }
  void setElement(T ee) {
    element = ee;
  }
  void setNext(Node *nn) {
    next = nn;
  }
};

template <typename T>
class Stack {
  Node<T> *head;
public:
  Stack() {
    head = NULL;
  }
  Stack(const Stack& ss) {
    head = NULL;
    Node<T> *tmp = peek();
    while(tmp) {
      push(tmp->getElement());
      tmp = tmp->getNext();
    }
  }  
  Stack& operator=(const Stack& ss) {
    Node<T> *tmp = ss.peek();

    while(pop() != 0);
    while(tmp) {
      insert(tmp->getElement());
      tmp = tmp->getNext();
    }
    return *this;
  }
    
  bool push(T elem) {
    Node<T> *newNode = new Node<T>(elem);
    if(!newNode) return false;
    newNode->setNext(head);
    head = newNode;
    return true;
  }
  T pop() {
    Node<T> *toDelete = head;
    if(!head) {
      std::cout << "Error : Empty Stack.\n";
      return T(0);
    }
    else {
      T ee = toDelete->getElement();
      head = head->getNext();
      delete toDelete;
      return ee;
    }
  }
  Node<T> *peek() const {
    return head;
  }
  int length() {
    Node<T> *tmp = head;
    int count = 0;
    while(tmp) {
      count++;
      tmp = tmp->getNext();
    }
    return count;
  }
  ~Stack() {
    Node<T> *tmp = head, *toDelete;
    while(tmp) {
      toDelete = tmp;
      tmp = tmp->getNext();
    }
    head = NULL;
  }
  friend std::ostream& operator<<(std::ostream& out, const Stack& ss) {
    Node<T> *tmp = ss.peek();
    while(tmp) {
      out << tmp->getElement() << " ";
      tmp = tmp->getNext();
    }
    out << "\n";
    return out;
  }
  int size() {
    int cnt = 0;
    Node<T> *tmp = head;
    while(tmp) {
      cnt++;
      tmp = tmp->getNext();
    }
    return cnt;
  } 
};

#endif
