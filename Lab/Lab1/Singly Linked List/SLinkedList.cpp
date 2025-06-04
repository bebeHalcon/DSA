#include<iostream>

using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(const T& item);

public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(T e) {
    Node* temp = new Node(e, NULL);
    if (count == 0)
    {
        head = temp;
        tail = temp; 
        count++;
        return;
    }
    /* Insert an element into the end of the list. */
    tail -> next = temp;
    tail = tail -> next;
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node* temp = new Node(e, NULL);
    if (index == 0)
    {
        temp -> next = head;
        head = temp;
        if(count == 0) tail = temp;
        count++;
        
        return;
    }
    Node * curr = head;
    if (index == count)
    {
        tail -> next = temp;
        tail = tail -> next;
        count++;
    }
    else 
    {
    for (int i=0; i<index-1; i++)
        curr = curr -> next;
    
    temp -> next = curr -> next;
    curr -> next = temp;
    count++;
    }
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;   
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index >= 0 && index < count) {
    Node * curr = head;
    for (int i = 0;i < index; i++)
        curr = curr -> next;
    return curr -> data;}
    return -1;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index >= 0 && index < count){
        Node * curr = head;
        for (int i = 0; i < index; i++)
            curr = curr -> next;
    
        curr -> data = e;
    }
    
    return;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node * curr= head;
    int i = 0;
    while(curr){
        
        if (curr -> data == item) return i;
        curr = curr -> next;
        i++;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node * curr = head;
    while(curr){
        
        if (curr -> data == item) return true;
        curr = curr -> next;
    }
    return false;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index == 0)
    {
        int res = head -> data;
        head = head -> next;
        count--;
        
        return res;
    }
    /* Remove element at index and return removed value */
    else if (index > 0 && index < count){
        
        Node* curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr -> next;
        if (index == count - 1){
            
            tail = curr;
        }
        int res = curr -> next -> data;
        curr -> next = curr -> next -> next;
        count--;
        return res;
    }
    
    return -1;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int i = 0;
    Node * curr = head;
    while (curr){
        
        if (curr -> data == item){
            
            removeAt(i);
            return true;
        }
        
        i++;
        curr = curr -> next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node * curr = head;
    while(curr){
        
        Node * temp = curr;
        curr = curr -> next;
        delete temp;
    }
    head = nullptr, tail = nullptr;
    count = 0;
}













