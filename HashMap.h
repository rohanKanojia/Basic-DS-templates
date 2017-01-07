#ifndef HASHMAP_H
#define HASHMAP_H

template<typename T1, typename T2>
class node {
  T1 data;
  T2 key;
  node *link;
public:
  node() : link(NULL) { }
  node(T1 d, T2 k, node *l) {
    this->data = d;
    this->key  = k;
    this->link = l;
  }
  T1 getData() { return data; }
  node *getLink() { return link; }
  T2 getKey() { return key; }
  void setData(T1 dd) { data = dd; }
  void setLink(node* l) { link = l; }
  void setKey(T2 k) { key = k; }
};

template<typename T2, typename T1>
class HashMap {
  int size;
  node<T1, T2> *arr;
  std::hash<T2> hashFunction;
public:
  HashMap(int sz) {
    this->size = sz;
    arr = new node<T1, T2>[sz];
  }
  void put(T2 key, T1 d) {
    int index = hashFunction(key);
    if(arr[index].getData() == -1) {
      /*
       * If the key is unused in hashmap.
       */
      arr[index].setData(d);
      arr[index].setKey(key);
    }
    else if(arr[index].getKey() == key) {
      /*
       * If key's data  is overwritten.
       */
      arr[index].setData(d);      
    }
    else {
      /*
       * Collission.
       */
       node<T1, T2> *tmp = arr[index].getLink();
       while(tmp != NULL && tmp->getLink() != NULL)
         tmp = tmp->getLink();
       tmp->setLink(new node<T1, T2>(d, key, NULL));
    }
  }
  bool containsKey(T2 key) {
    int index = hashFunction(key);
    if(arr[index].getData() == -1)
      return false;
    else if(arr[index].getKey() == key)
      return true;
    else {
      node<T1, T2> *tmp = arr[index].getLink();
      while(tmp) {
        if(tmp->getKey() == key)
          return true;
        tmp = tmp->getLink();
      }
      return false;
    }
  }
  T1 get(T2 key) {
    int index = hashFunction(key);
    if(arr[index].getKey() == key) {
      return arr[index].getData();
    }
    else {
      node<T1, T2> *tmp = arr[index].getLink();
      while(tmp != NULL && tmp->getLink() != NULL) {
        if(tmp->getKey() == key)
          return arr[index].getData();
        tmp = tmp->getLink();
      }
      return -1;
    }
  }
};
#endif
