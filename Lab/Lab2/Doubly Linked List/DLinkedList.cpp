template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count) return;
    Node* newNode = new Node(e);
    if (index == 0){
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
    else{
        Node* temp = head;
        for (int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr){
            temp->next->previous = newNode;
        }
        temp->next = newNode;
        newNode->previous = temp;
        if (index == count){
            tail = newNode;
        }
    }
    count++;
}

template<class T>                                                                                                       
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this-> count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count || count == 0){
        return T();
    }
    Node* temp = head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count || count == 0) return;
    if (index == 0) head->data = e;
    else{
        Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        temp->data = e;
    }
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (count == 0) return -1;
    Node* temp = head;
    for (int i = 0; i < count; i++){
        if (temp->data == item){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* temp = head;
    for (int i = 0; i < count; i++){
        if (temp->data == item) return true;
        temp = temp->next;
    }
    return false;
}