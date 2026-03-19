#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // reverse function
    ListNode *reverse(ListNode* head){
        ListNode *p = head, *q = NULL, *r = NULL;
        while(p != NULL){
            r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        return q;
    }

    // reverse k group
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *p = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *first = dummy;

        while(p != NULL){

            ListNode *temp = new ListNode(-1);
            ListNode *d = temp;

            // build group
            for(int i = 0; i < k; i++){
                if(p == NULL) return dummy->next;
                temp->next = p;
                temp = temp->next;
                p = p->next;
            }

            temp->next = NULL;

            d = d->next; // actual group start

            // reverse group
            ListNode* revHead = reverse(d);

            // attach
            first->next = revHead;
            first = d;

            // connect to next part
            d->next = p;
        }

        return dummy->next;
    }
};

// insert at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) return newNode;

    ListNode* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return head;
}

// print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* head = NULL;

    // create list: 1 → 2 → 3 → 4 → 5
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    int k = 3;

    head = obj.reverseKGroup(head, k);

    cout << "\nAfter reversing in groups of " << k << ":\n";
    printList(head);

    return 0;
}