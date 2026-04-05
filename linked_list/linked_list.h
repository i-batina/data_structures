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

  // copy constructor so a copys nodes arent tied to same memory
  LinkedList(const LinkedList& other) : head_(nullptr), tail_(nullptr), size_(0) {
    Node* current = other.head_;
    while (current != nullptr) {
      pushTail(current->value);
      current = current->next;
    }
  }

  // assignment operator
  LinkedList& operator=(LinkedList other) {
    swap(other);
    return *this;
  }

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

 private:
  void swap(LinkedList& o);
};
