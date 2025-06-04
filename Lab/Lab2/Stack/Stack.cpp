template <class T>
class DLinkedList 
{
public:
    class Node;     //forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};

#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif

void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(item);
}

T pop() {
    // TODO: Remove an element on top of the stack
    if (!empty()){
        T val = top();
        list.removeAt(list.size() - 1);
        return val;
    }
    else return T();
}

T top() {
    // TODO: Get value of the element on top of the stack
    if (!empty()){
        return list.get(list.size() - 1);
    }
    else return T();
}

bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return list.size();
}

void clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}