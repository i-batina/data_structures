#include <iostream>

struct Node {
  int   value;
  Node* next;
  Node* prev;

  Node(int val) {
    value = val;
    next  = nullptr;
    prev  = nullptr;
  }
};

class LinkedList {
 private:
  Node* head_;
  Node* tail_;
  int   size_;
  int   capacity_ = 999;

 public:
  LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  ~LinkedList() {
    Node* current = head_;
    while (current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }

  // Note: add copy constructor and assignment operator

  void insert(int idx, int val);

  void remove(int val);

  bool contains(int val);

  int indexOf(int val);

  void reverse();

  // void sort();

  void pushTail(int val);

  void pushHead(int val);

  void popTail();

  void popHead();

  Node* getNode(int idx);

  Node* getHead();

  Node* getTail();

  int getSize();

  bool isEmpty();

  // helper
  void printFun();

  void printReverse();
};
