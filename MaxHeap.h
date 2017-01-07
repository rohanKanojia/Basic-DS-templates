#ifndef MAX_HEAP
#define MAX_HEAP

#include <vector>
#include <stdexcept>

template <typename T>
class MaxHeap {
  std::vector<T> items;
  int size, capacity;
  int getLeftChildIndex(int index)       { return 2*index + 1; }
  int getRightChildIndex(int index)      { return 2*index + 2; }
  int getParentIndex(int index)          { return (index-1)/2; }
  bool hasRightChild(int index)          { return getRightChildIndex(index) < size; }
  bool hasLeftChild(int index)           { return getLeftChildIndex(index) < size; }
  bool hasParent(int index)              { return getParentIndex(index) >= 0; }
  T leftChild(int index)                 { return items[getLeftChildIndex(index)]; }
  T rightChild(int index)                { return items[getRightChildIndex(index)]; }
  T parent(int index)                    { return items[getParentIndex(index)]; }
  void swap(int indexOne, int indexTwo) {
    T tmp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = tmp;
  }
  void ensureExtraCapacity() {
    if(size == capacity)
      items.resize(size*2);
  }
public:
  MaxHeap() : size(0), capacity(100) {
    items.resize(capacity);
  }
  T peek() {
    if(size == 0)
      throw std::invalid_argument("Heap is empty");
    return items[0];
  }
  T poll() { /* delete item */
    if(size == 0)
      throw std::invalid_argument("Heap is empty");
    T item = items[0];
    items[0] = items[size-1];
    size--;
    heapifyDown();
  }
  void add(T item) {
    ensureExtraCapacity();
    items[size] = item;
    size++;
    heapifyUp();
  }
  void heapifyUp() {
    int index = size-1;

    while(hasParent(index) && parent(index) < items[index]) {
      swap(getParentIndex(index), index);
      index = getParentIndex(index);
    }
  }
  void heapifyDown() {
    int index = 0;

    while(hasLeftChild(index)) {
      int largerChildIndex = getLeftChildIndex(index);
      
      if(hasRightChild(index) && rightChild(index) > items[largerChildIndex])
        largerChildIndex = getRightChildIndex(index);

      if(items[index] > items[largerChildIndex])
        break;
      else {
        swap(largerChildIndex, index);
        index = largerChildIndex;
      }
    }
  }
};

#endif
