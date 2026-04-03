#include "linked_list.h"

void LinkedList::pushTail(int value) { insert(getSize(), value); }

void LinkedList::pushHead(int value) { insert(0, value); }

void LinkedList::insert(int idx, int value) {
  // empty list, insert at head
  if (isEmpty()) {
    Node* node = new Node(value);
    head       = node;
    tail       = node;
    node->idx  = 0;
    head->next = nullptr;
    size++;
    return;
  }

  // invalid idx or full list
  if (idx > getSize() || idx < 0) {
    printf("Invalid Index");
    return;
  } else if (getSize() == capacity - 1) {
    printf("List Full");
    return;
  }

  Node* node = new Node(value);
  if (idx == 0) {
    node->next = head;
    head->prev = node;
    head       = node;
    Node* temp = head->next;
    while (temp != nullptr) {
      temp->idx++;
      temp = temp->next;
    }
    node->idx = idx;
    size++;
  }

  // insert at tail if idx is end
  else if (idx == getSize()) {
    node->prev = tail;
    tail->next = node;
    tail       = node;
    node->next = nullptr;
    node->idx  = idx;
    size++;
  } else {  // insert anywhere else
    Node* before = getNode(idx - 1);
    Node* after  = getNode(idx);
    node->prev   = before;
    node->next   = after;
    before->next = node;
    after->prev  = node;

    Node* current = node->next;
    while (current != nullptr) {
      current->idx++;
      current = current->next;
    }
    node->idx = idx;
    size++;
  }
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

bool LinkedList::isEmpty() {
  if (getSize() == 0)
    return true;
  else
    return false;
}

void LinkedList::printFun() {
  Node* current = head;
  if (head == nullptr) return;
  while (current != nullptr) {
    printf("| %i ", current->value);
    current = current->next;
  }
  printf("\n");
  return;
}
