#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode *p=head,*q=head,*r=head;
        int c=0;

        // count length
        while(q!=NULL){
            c++;
            q=q->next;
        }

        k = k % c;
        if(k == 0) return head;

        q = head;
        k = c - k;

        // find new tail
        while(q->next != NULL){
            if(k > 1){
                p = p->next;
                k--;
            }
            q = q->next;
        }

        // make circular
        q->next = r;

        // new head
        r = p->next;

        // break
        p->next = NULL;

        return r;
    }
};

// 🔧 Utility: print list
void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // 🔹 Create Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;  

    cout << "Original List: ";
    printList(head);

    Solution obj;
    ListNode* newHead = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(newHead);

    return 0;
}