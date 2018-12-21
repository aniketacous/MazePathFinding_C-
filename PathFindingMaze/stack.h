#ifndef _STACK_H
#define _STACK_H

#include <exceptions.h>

const int STACK_SIZE = 16;

template <class StackType>
class Stack {
 public:
  Stack() {

    top = 0;
    data = new StackType[STACK_SIZE];
    capacity = STACK_SIZE;
  }
  ~Stack() {

    delete[] data;
  }

  int size() { return top; }
  bool isEmpty() { return !top; }

  void clear() { top = 0; }

  void push(StackType d) {

    if (top == STACK_SIZE) {
      StackType *tmpData = new StackType[2*capacity];
      for (int i=0;i<capacity;i++)
        tmpData[i] = data[i];
      delete[] data;
      data = tmpData;
      capacity *= 2;
    }

    data[top++] = d;
  }

  StackType pop() {

    if (top == 0)
      throw ContainerEmptyException();

    return data[--top];
  }

  
  StackType peek() {

    if (top == 0)
      throw ContainerEmptyException();

    return data[top-1];
  }

 private:
  StackType
    *data;
  int
    capacity,
    top;
};

#endif

