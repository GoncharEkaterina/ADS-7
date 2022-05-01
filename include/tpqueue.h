// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
 TPQueue::ITEM*create(const T &data) {
 ITEM *item = new ITEM;
 item->data = data;
 item->next = nullptr;
 return item;
}
 int *head;
 int *tail;
 struct ITEM {
  T data;
  ITEM * next;
  ITEM * prev;
 };
 
 public:
 T pop() {
 if (head) {
  ITEM *temp = head->next;
  T data = head->data;
  delete head;
  head = temp;
  return data;
 } else { throw std::string("Empty"); }
 }
 T push(const T &data) {
  ITEM *temp = head;
  ITEM *item = create(data);
  while (temp && temp->prior.data >= data.prior) {
   tail = tail->next;
   if (!temp && head) {
    tail->next = item;
    tail->next->prev = tail;
    tail = item;
   } else if (!temp && !head) { 
    head = item = tail;
   } else if (!temp->prev) {
    temp->prev = item;
    item->next = temp;
    head = item;
   } else {
    temp->prev->next = item;
    item->next = temp;
    item->prev = item;
  }
 }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
