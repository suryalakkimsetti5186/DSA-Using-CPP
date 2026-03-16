#include <bits/stdc++.h>
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
    bool hasCycle(ListNode *head) {

        ListNode *p = head;
        ListNode *q = head;

        while(q != NULL && q->next != NULL){

            p = p->next;
            q = q->next->next;

            if(p == q)
                return true;
        }

        return false;
    }
};

int main() {

    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating a cycle: 4 -> 2
    fourth->next = second;

    Solution obj;

    if(obj.hasCycle(head))
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}