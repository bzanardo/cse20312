// Maria Beatriz Zanardo
// Lab 3

#ifndef _NODE_H_
#define _NODE_H_

#include <cstdlib>

template<typename T> class LinkedList;

template<typename T>
class Node {
  
  friend class LinkedList<T>;

  public:
    Node(const T &);  
    T getData() const;
    Node<T> *next;

  private:
    T data;
};

template<typename T>
Node<T>::Node(const T &info) :data(info),next(NULL) {} 		// Constructor

template<typename T>
T Node<T>::getData(void) const { 
  return data; 
}

#endif 


#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class LinkedList {
  public:
    LinkedList();
    ~LinkedList();
    void pushFront(const T &);
    void print();
    bool empty();
    int nodeCount();
    Node<T> *head;
  private:
    Node<T> *newNode(const T &);
};

template<typename T>
LinkedList<T>::LinkedList() :head(NULL) {} 		// Constructor

template<typename T>
LinkedList<T>::~LinkedList() {
  if (!empty()) {
    Node<T> *p=head;
    while (p != NULL) {
      Node<T> *next = p->next;
      delete p;
      p = next;
    }
  }
}

template<typename T>
void LinkedList<T>::pushFront(const T &value) {
  Node<T> *x = newNode(value);
  x->next = head;
  head = x;
}

template<typename T>
bool LinkedList<T>::empty() { 
  return (head == NULL); 
}

template<typename T>
void LinkedList<T>::print() {
  Node<T> *p = head;
  for ( ; p != NULL; p = p->next) {
    cout << p->getData() << endl;
  }
}

template<typename T>
Node<T> *LinkedList<T>::newNode(const T &value) {
  return new Node<T>(value);
}

template<typename T>
int LinkedList<T>::nodeCount() {
  int n = 0;
  for(Node<T> *p = head; p != NULL; p = p->next) { 
    n++;
  }
  return n;
}

#endif

#include <string>

template<typename T>
LinkedList<T> addNumberLists(LinkedList<T> &l1, LinkedList<T> &l2);

int main() {

  LinkedList<int> Num1;
  LinkedList<int> Num2;
  string numString1, numString2;
  int num1, num2;

  cin >>  numString1 >> numString2;
  for (auto it1 = numString1.begin(); it1 != numString1.end(); it1++) {
    num1 = (*it1) - '0';
    Num1.pushFront(num1);   
  }

  for (auto it2 = numString2.begin(); it2 != numString2.end(); it2++) {
    num2 = (*it2) - '0';
    Num2.pushFront(num2);   
  }

  LinkedList<int> Sum = addNumberLists(Num1, Num2);
  Sum.print();
}

template<typename T>
LinkedList<T> addNumberLists(LinkedList<T> &l1, LinkedList<T> &l2) {

LinkedList<int> result;
int num1, num2, sum;
int carry = 0;

  if (l1.nodeCount() > l2.nodeCount()) {
    Node<T> *p2 = l2.head;
    for (Node<T> *p1 = l1.head; p1 != NULL; p1 = p1->next) {
      if (p1 == NULL) {
        num1 = 0;
      }  
      else {
        num1 = p1->getData();
      }

      if (p2 == NULL) {
        num2 = 0;
      }
      else {
        num2 = p2->getData();
      }

      sum = num1 + num2 + carry; 
      carry = 0;

      if (sum >= 10) {
        sum = sum - 10;
        carry = 1;
      }
      result.pushFront(sum);
      
      if (p2 != NULL) { 
        p2 = p2->next;
      }
    }
    return result;
  }

  else {
    Node<T> *p1 = l1.head;
    for (Node<T> *p2 = l2.head; p2 != NULL; p2 = p2->next) {
      if (p1 == NULL) {
        num1 = 0;
      }
      else {
        num1 = p1->getData();
      }

      if (p2 == NULL) {
        num2 = 0;
      }
      else {
        num2 = p2->getData();
      }

      sum = num1 + num2 + carry;
      carry = 0;

      if (sum >= 10) {
        sum = sum - 10;
        carry = 1;
      }
      result.pushFront(sum);

      if (p1 != NULL) {
        p1 = p1->next;
      }
    }
    return result;
  } 

}
