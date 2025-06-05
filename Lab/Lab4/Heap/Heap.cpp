#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return count == 0;
}

template<class T>
T Heap<T>::peek(){
    if (count == 0) return -1;
      return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i=0; i<count; i++)
          if (elements[i] == item) return true;
      return false;
}

template<class T>
bool Heap<T>::pop(){
    if (count == 0) return -1;
      elements[0] = elements[count-1];
      count--;
      reheapDown(0);
      return true;
}

template<class T>
void Heap<T>::push(T item){
    if (count == capacity) ensureCapacity(capacity+1);
    elements[count] = item;
    count++;
    int index = count - 1;
    reheapUp(index);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* res = new T[minCapacity];
    for (int i=0; i<capacity; i++)
    {
        res[i] = elements[i];
    }
    capacity = minCapacity;
    delete[] elements;
    elements = res;
}

template<class T>
void Heap<T>::reheapUp(int i){
    if (i && elements[(i-1)/2] < elements[i])
    {
        swap(elements[i], elements[(i-1)/2]);
        reheapUp((i-1)/2);
    }
}

int left(int i) {
    return (2*i + 1);
}
 
int right(int i) {
    return (2*i + 2);
}

void reheapDown(int maxHeap[], int numberOfElements, int i)
{
    int temp_left = left(i);
    int temp_right = right(i);
 
    int largest = i;
    if (temp_left < numberOfElements && maxHeap[temp_left] > maxHeap[i]) 
    {
        largest = temp_left;
    }
 
    if (temp_right < numberOfElements && maxHeap[temp_right] > maxHeap[largest]) 
    {
        largest = temp_right;
    }
        
    if (largest != i)
    {
        swap(maxHeap[i], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

int parent(int i) {
    return (i - 1) / 2;
}

void reheapUp(int maxHeap[], int numberOfElements, int i)
{
    if (i && maxHeap[parent(i)] < maxHeap[i])
    {
        swap(maxHeap[i], maxHeap[parent(i)]);
        reheapUp(maxHeap, numberOfElements, parent(i));
    }
}

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i=0; i<count; i++) {
        if(elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    elements[index] = elements[--count];
    reheapUp(index);
    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    count = 0;
}