#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;

        while(p != q){
            p = (p == NULL) ? headB : p->next;
            q = (q == NULL) ? headA : q->next;
        }

        return p;
    }
};

// Helper to print list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // Common part (intersection)
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    Solution obj;
    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if(intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}