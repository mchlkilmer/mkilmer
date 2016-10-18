//: C16:OwnerStack.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Stack with runtime conrollable ownership
#ifndef OWNERSTACK_H
#define OWNERSTACK_H
#include <vector>

template<class T> class Stack {
  struct Link {
    T* data;
    Link* next;
    Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
  };
  Link* head;

public:
	vector<Link*> myVector;

  Stack(){}
  ~Stack();

  void push(T* dat) {
    myVector.push_back(T* dat);
  }

  T* peek() const { 
    return head ? head->data : 0; 
  }

  T* pop();

  /*bool owns() const { return own; }*/
  //void owns(bool newownership) {
  //  own = newownership;
  //}
  // Auto-type conversion: true if not empty:
  operator bool() const { return head != 0; }
};

template<class T> T* Stack<T>::pop() {
	if(head == 0) return 0;
	result = myVector.back();
	myVector.pop_back()
	return result;
}

template<class T> Stack<T>::~Stack() {
  if(!own) return;
  while(head)
    delete pop();
}
#endif // OWNERSTACK_H ///:~
