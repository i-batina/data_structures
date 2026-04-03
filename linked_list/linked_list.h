#include <iostream>

struct Node {
  int   value;
  int   idx;
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
  Node* head;
  Node* tail;
  int   size;
  int   capacity = 999;

 public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  ~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }

  // Note: add copy constructor and assignment operator

  void pushTail(int val);

  void pushHead(int val);

  void pop();

  void insert(int idx, int val);

  void remove(int val);

  void remove(Node* node);

  Node* getNode(int idx);

  Node* getHead();

  int getSize();

  bool isEmpty();

  // helper
  void printFun();
};
