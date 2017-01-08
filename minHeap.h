#ifndef MIN_HEAP
#define MIN_HEAP

#include <vector>
#include <stdexcept>

template <typename T>
class MinHeap {
  std::vector<T> items;
  int size;
  int getLeftChildIndex(int parentIndex)   { return 2*parentIndex + 1; }
  int getRightChildIndex(int parentIndex)  { return 2*parentIndex + 2; }
  int getParentIndex(int childIndex)       { return (childIndex-1)/2;  }
  bool hasLeftChild(int index)             { return getLeftChildIndex(index) < size; }
  bool hasRightChild(int index)            { return getRightChildIndex(index) < size; }
  bool hasParent(int index)                { return getParentIndex(index) >= 0; }
  T leftChild(int index)                   { return items[getLeftChildIndex(index)]; }
  T rightChild(int index)                  { return items[getRightChildIndex(index)]; }
  T parent(int index)                      { return items[getParentIndex(index)]; }
  void swap(int indexOne, int indexTwo) {
    T tmp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = tmp;
  }
public:
  MinHeap() : size(0) { }
  T peek() {
    if(size == 0) throw std::invalid_argument("Heap is empty");

    return items[0];
  }
  T poll() { /* delete item */
    if(size == 0) throw std::invalid_argument("Heap is empty");

    T item = items[0];
    items[0] = items[size-1];
    items.pop_back();
    size--;
    heapifyDown();
    return item;
  }
  void add(T item) {
    items.push_back(item);
    size++;
    heapifyUp();
  }
  void heapifyUp() {
    int index = size-1;
    while(hasParent(index) && parent(index) > items[index]) {
      swap(getParentIndex(index), index);
      index = getParentIndex(index);
    }
  }
  void heapifyDown() {
    int index = 0;

    while(hasLeftChild(index)) {
      // We're looking for left child because heap is a compact data structure.
      // if there's is a child, it must be a left child.
      int smallerChildIndex = getLeftChildIndex(index);
      if(hasRightChild(index) && rightChild(index) < items[smallerChildIndex]) 
        smallerChildIndex = getRightChildIndex(index);

      if(items[index] < items[smallerChildIndex]) 
        break; // Heap is in order
      else {
        swap(index, smallerChildIndex);
        index = smallerChildIndex;
      }
    }
  }
  bool isEmpty() { return size == 0; }
  int getSize()     { return size; }
};
#endif
