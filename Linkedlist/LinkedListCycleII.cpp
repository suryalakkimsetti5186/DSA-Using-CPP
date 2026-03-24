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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;

        while(q != NULL && q->next != NULL){
            p = p->next;
            q = q->next->next;

            if(p == q){
                q = head;
                while(q != p){
                    q = q->next;
                    p = p->next;
                }
                return q;
            }
        }
        return NULL;
    }
};

int main(){

    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Linking nodes
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Creating a cycle (5 -> 3)
    n5->next = n3;

    Solution obj;
    ListNode* res = obj.detectCycle(head);

    if(res != NULL)
        cout << "Cycle starts at node with value: " << res->val;
    else
        cout << "No cycle detected";

    return 0;
}