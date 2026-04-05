#include "linked_list.h"

void LinkedList::insert(int idx, int value) {
  // empty list, insert at head
  if (isEmpty()) {
    Node* node  = new Node(value);
    head_       = node;
    tail_       = node;
    node->idx   = 0;
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
    while (temp != nullptr) {
      temp->idx++;
      temp = temp->next;
    }
    node->idx = idx;
    size_++;
  }

  // insert at tail if idx is end
  else if (idx == getSize()) {
    node->prev  = tail_;
    tail_->next = node;
    tail_       = node;
    node->next  = nullptr;
    node->idx   = idx;
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
    while (current != nullptr) {
      current->idx++;
      current = current->next;
    }
    node->idx = idx;
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
  if (idx == tail_->idx) {
    Node* temp  = tail_;
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
    Node* current = head_;
    int   count   = 0;
    while (current != nullptr) {
      current->idx = count;
      current      = current->next;
      count++;
    }
    size_--;
  }

  // else remove node
  else {
    Node* current       = getNode(idx);
    current->next->prev = current->prev;
    current->prev->next = current->next;
    Node* temp          = current;
    current             = current->next;
    while (current != nullptr) {
      current->idx--;
      current = current->next;
    }
    delete temp;
    temp = nullptr;
    size_--;
  }
}

Node* LinkedList::getNode(int idx) {
  if (idx > getSize() - 1 || idx < 0 || isEmpty()) return nullptr;
  if (getSize() == 1) return getHead();
  if (idx == getSize() - 1) return getTail();

  Node* current = head_;
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

void LinkedList::pushTail(int value) { insert(getSize(), value); }

void LinkedList::pushHead(int value) { insert(0, value); }

void LinkedList::pop() {
  if (!isEmpty()) remove(getTail()->idx);
}

int LinkedList::getSize() { return size_; }

Node* LinkedList::getHead() { return head_; }

Node* LinkedList::getTail() { return tail_; }

void LinkedList::printFun() {
  Node* current = head_;
  if (head_ == nullptr) return;
  while (current != nullptr) {
    printf("| %i ", current->value);
    current = current->next;
  }
  printf("\n");
  return;
}
