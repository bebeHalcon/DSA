#ifndef QUEUE_H
#define QUEUE_H
#include "DLinkedList.h"

template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif /* QUEUE_H */

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


void push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}

T pop() {
    // TODO: Remove an element in the head of the queue
    if (!empty()){
        T val = top();
        list.removeAt(0);
        return val;
    }
    else return T();
}

T top() {
    // TODO: Get value of the element in the head of the queue
    if (!empty()){
        return list.get(0);
    }
    else return T();
}

bool empty() {
    // TODO: Determine if the queue is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the queue
    return list.size();
}

void clear() {
    // TODO: Clear all elements of the queue
    list.clear();
}