#include "linked_list.h"

void LinkedList::pushTail(int value) { insert(getSize() - 1, value); }

void LinkedList::pushHead(int value) {
  if (size == capacity - 1)  // Full list
    return;

  Node* node = new Node(value);
  node->idx  = 0;

  if (size == 0) {  // empty list
    head = node;
    tail = head;
  } else {
    node->next    = head;
    head->prev    = node;
    head          = node;
    Node* current = head;
    for (int i = 0; i < size; i++) {
      current = current->next;
      current->idx++;
    }
  }
  size++;
}

void LinkedList::insert(int idx, int value) {
  // empty list, insert at head
  if (getSize() == 0) {
    Node* node = new Node(value);
    head       = node;
    head->next = nullptr;
    return;
  }

  // invalid idx or full list
  if (idx > getSize() - 1 || idx < 0) {
    printf("Invalid Index");
    return;
  } else if (getSize() == capacity - 1) {
    printf("List Full");
    return;
  }

  Node* node = new Node(value);
  if (idx == 0) {
  }

  // insert at tail if idx is end
  else if (idx == tail->idx) {
    node->prev = tail;
    tail       = node;
    node->next = nullptr;
  } else {  // insert anywhere else
    node->prev = getNode(idx - 1);
    node->next = getNode(idx + 1);

    Node* current = node;
    for (int i = idx; i < size; i++) current->next->idx++;
  }
  size++;
  tail->idx = size - 1;
}

void LinkedList::pop() { remove(tail); }

void LinkedList::remove(int value) {}

void LinkedList::remove(Node* node) {
  if (node == nullptr) return;
  // if tail

  // if head

  // else remove node

  size--;
}

int LinkedList::getSize() { return size; }

Node* LinkedList::getHead() { return head; }

Node* LinkedList::getNode(int idx) {
  if (idx > getSize() - 1 || idx < 0) return nullptr;

  Node* current = head;
  int   count   = 0;

  while (count != idx) {
    current = current->next;
    count++;
  }
  return current;
}

void LinkedList::printFun() {
  Node* current = head;
  if (head == nullptr) return;
  while (current != nullptr) {
    printf("| %i\n", current->value);
    current = current->next;
  }
  return;
}
