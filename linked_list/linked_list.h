#include <iostream>

struct Node {
  int value;
  int idx;
  Node *next;
  Node *prev;

  Node(int val) {
    value = val;
    next = nullptr;
    prev = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int size;
  int capacity = 999;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  ~LinkedList() {
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
      delete current->prev;
      current->prev = nullptr;
    }
  }

  // Note: add copy constructor and assignment operator

  void pushTail(int val);

  void pushHead(int val);

  void pop();

  void insert(int idx, int val);

  void remove(int val);

  void remove(Node *node);

  Node *getNode(int idx);

  Node *getHead();

  int getSize();

  // helper
  void printFun();
};
