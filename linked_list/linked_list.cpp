#include "linked_list.h"

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
    size++;
  }
}

void LinkedList::remove(int idx) {
  if (idx >= getSize() || idx < 0 || isEmpty()) return;

  // if size is 1
  if (getSize() == 1) {
    delete head;
    tail = nullptr;
    head = nullptr;
    size = 0;
    return;
  }

  // if tail
  if (idx == tail->idx) {
    Node* temp = tail;
    tail       = tail->prev;
    tail->next = nullptr;
    delete temp;
    temp = nullptr;
    size--;
    return;
  }

  // if head
  else if (idx == 0) {
    head = head->next;
    delete head->prev;
    head->prev    = nullptr;
    Node* current = head;
    int   count   = 0;
    while (current != nullptr) {
      current->idx = count;
      current      = current->next;
      count++;
    }
    size--;
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
    size--;
  }
}

Node* LinkedList::getNode(int idx) {
  if (idx > getSize() - 1 || idx < 0 || isEmpty()) return nullptr;
  if (getSize() == 1) return getHead();
  if (idx == getSize() - 1) return getTail();

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

void LinkedList::pushTail(int value) { insert(getSize(), value); }

void LinkedList::pushHead(int value) { insert(0, value); }

void LinkedList::pop() {
  if (!isEmpty()) remove(getTail()->idx);
}

int LinkedList::getSize() { return size; }

Node* LinkedList::getHead() { return head; }

Node* LinkedList::getTail() { return tail; }

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
