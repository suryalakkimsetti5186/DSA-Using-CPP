#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

// Insert at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) return newNode;

    ListNode* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Print DLL
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Your function
ListNode* removeDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* curr = head;

    while (curr->next != NULL) {
        if (curr->val == curr->next->val) {
            ListNode* dup = curr->next;

            curr->next = dup->next;

            if (dup->next != NULL) {
                dup->next->prev = curr;
            }

            delete dup;
        } 
        else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    ListNode* head = NULL;

    // Create sorted DLL: 1 <-> 2 <-> 2 <-> 3 <-> 3 <-> 4
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    cout << "Original List:\n";
    printList(head);

    head = removeDuplicates(head);

    cout << "\nAfter Removing Duplicates:\n";
    printList(head);

    return 0;
}