struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};
 
// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode* c = new ListNode(0);
    ListNode* tmp = c;
    while (a && b){
        if (a -> val > b -> val){
            tmp -> next = b;
            b = b -> next;
        }
        else{
            tmp -> next = a;
            a = a -> next;
        }
        tmp = tmp -> next;
    }
    while (a){
        tmp -> next = a;
        a = a -> next;
        tmp = tmp -> next;
    }
    while (b){
        tmp -> next = b;
        b = b -> next;
        tmp = tmp -> next;
    }
    return c -> next;
}

// Sort and unsorted list given its head pointer

ListNode* mergeSortList(ListNode* head){
    if (head == nullptr || head -> next == nullptr) return head;
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    if (fast_ptr -> next -> next != nullptr){
        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
    ListNode * temp = slow_ptr -> next;
    slow_ptr -> next = nullptr;
    head = mergeSortList(head);
    temp = mergeSortList(temp);
    return mergeLists(head, temp);
}