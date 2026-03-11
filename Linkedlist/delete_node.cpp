#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *q = node;
        q->val = q->next->val;
        q->next = q->next->next;
    }
};

ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val;
        if (current->next != NULL) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

ListNode* findNode(ListNode* head, int value) {
    ListNode* current = head;
    while (current != NULL) {
        if (current->val == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, n);
    
    std::cout << "Original linked list: ";
    printList(head);
    
    ListNode* nodeToDelete = findNode(head, 3);
    
    if (nodeToDelete != NULL && nodeToDelete->next != NULL) {
        std::cout << "Deleting node with value: " << nodeToDelete->val << std::endl;
        
        Solution solution;
        solution.deleteNode(nodeToDelete);
        
        std::cout << "Linked list after deletion: ";
        printList(head);
    }
    
    return 0;
}