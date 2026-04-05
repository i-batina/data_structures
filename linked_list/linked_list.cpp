#include "linked_list.h"

void LinkedList::insert(int idx, int value) {
  // empty list, insert at head
  if (isEmpty()) {
    Node* node  = new Node(value);
    head_       = node;
    tail_       = node;
    head_->next = nullptr;
    size_++;
    return;
  }

  // invalid idx or full list
  if (idx > getSize() || idx < 0) {
    printf("Invalid Index");
    return;
  } else if (getSize() == capacity_) {
    printf("List Full");
    return;
  }

  Node* node = new Node(value);
  if (idx == 0) {
    node->next  = head_;
    head_->prev = node;
    head_       = node;
    Node* temp  = head_->next;
    size_++;
  }

  // insert at tail if idx is end
  else if (idx == getSize()) {
    node->prev  = getTail();
    tail_->next = node;
    tail_       = node;
    node->next  = nullptr;
    size_++;
  }

  // insert anywhere else
  else {
    Node* before = getNode(idx - 1);
    Node* after  = getNode(idx);
    node->prev   = before;
    node->next   = after;
    before->next = node;
    after->prev  = node;

    Node* current = node->next;
    size_++;
  }
}

void LinkedList::remove(int idx) {
  if (idx >= getSize() || idx < 0 || isEmpty()) return;

  // if size is 1
  if (getSize() == 1) {
    delete head_;
    tail_ = nullptr;
    head_ = nullptr;
    size_ = 0;
    return;
  }

  // if tail
  if (idx == getSize() - 1) {
    Node* temp  = getTail();
    tail_       = tail_->prev;
    tail_->next = nullptr;
    delete temp;
    temp = nullptr;
    size_--;
    return;
  }

  // if head
  else if (idx == 0) {
    head_ = head_->next;
    delete head_->prev;
    head_->prev   = nullptr;
    Node* current = getHead();
    int   count   = 0;
    size_--;
  }

  // else remove node
  else {
    Node* current       = getNode(idx);
    current->next->prev = current->prev;
    current->prev->next = current->next;
    Node* temp          = current;
    current             = current->next;
    delete temp;
    temp = nullptr;
    size_--;
  }
}

bool LinkedList::contains(int val) {
  Node* current = getHead();
  while (current != nullptr && current->value != val) current = current->next;
  return (current != nullptr);
}

int LinkedList::indexOf(int val) {
  Node* current = getHead();
  int   count   = 0;
  while (current != nullptr && current->value != val) {
    current = current->next;
    count++;
  }
  return current != nullptr ? count : -9999;
}

void LinkedList::reverse() {
  if (isEmpty()) return;
  Node* current = getHead();
  Node* temp    = nullptr;
  while (current != nullptr) {
    temp          = current->next;  // store old nodes next
    current->next = current->prev;  // set old nodes next as its previous
    current->prev = temp;           // set old nodes prev as its old next
    current       = temp;           // current is now the nodes old next
  }
  temp  = getHead();
  head_ = getTail();
  tail_ = temp;
}

Node* LinkedList::getNode(int idx) {
  if (idx > getSize() - 1 || idx < 0 || isEmpty()) return nullptr;
  if (getSize() == 1) return getHead();
  if (idx == getSize() - 1) return getTail();

  Node* current = getHead();
  int   count   = 0;
  while (count != idx) {
    current = current->next;
    count++;
  }
  return current;
}

bool LinkedList::isEmpty() { return getSize() == 0; }

void LinkedList::pushTail(int value) { insert(getSize(), value); }

void LinkedList::pushHead(int value) { insert(0, value); }

void LinkedList::popTail() {
  if (!isEmpty()) remove(getSize() - 1);
}

void LinkedList::popHead() {
  if (!isEmpty()) remove(0);
}

int LinkedList::getSize() { return size_; }

Node* LinkedList::getHead() { return head_; }

Node* LinkedList::getTail() { return tail_; }

void LinkedList::printFun() {
  Node* current = getHead();
  if (current == nullptr) return;
  while (current != nullptr) {
    printf("| %i ", current->value);
    current = current->next;
  }
  printf("\n");
}

void LinkedList::printReverse() {
  Node* current = getTail();
  if (current == nullptr) return;
  while (current != nullptr) {
    printf("| %i ", current->value);
    current = current->prev;
  }
  printf("\n");
}

void LinkedList::swap(LinkedList& o) {
  Node* tH = getHead();
  Node* tT = getTail();
  int   tS = getSize();
  head_    = o.head_;
  tail_    = o.tail_;
  size_    = o.size_;
  o.head_  = tH;
  o.tail_  = tT;
  o.size_  = tS;
}