// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
  T data;
  Node* next;
  explicit Node(const T& value) : data(value), next(nullptr) {
  }
  };
  Node* head;
  Node* tail;

 public:
  TPQueue() : head(nullptr), tail(nullptr) {
  }
  ~TPQueue() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
void push(const T& item) {
  Node* newNode = new Node(item);
    if (head == nullptr || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      if (tail == nullptr) {
         tail = newNode;
      }
      return;
    }
    Node* current = head;
    while (current->next != nullptr &&
     current->next->data.prior >= item.prior) {
     current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == nullptr) {
     tail = newNode;
    }
  }
T pop() {
  if (head == nullptr) {
     throw std::underflow_error("Queue is empty");
  }
  Node* temp = head;
  T result = head->data;
  head = head->next;
    if (head == nullptr) {
     tail = nullptr;
    }
    delete temp;
    return result;
}
bool isEmpty() const {
    return head == nullptr;
}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
