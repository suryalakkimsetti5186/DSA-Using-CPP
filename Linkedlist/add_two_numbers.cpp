#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;

        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *dummy = head;

        while(p != NULL || q != NULL || carry){
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            dummy->next = temp;
            dummy = dummy->next;

            if(p) p = p->next;
            if(q) q = q->next;
        }

        return head->next;
    }
};

// Utility: create list
ListNode* createList(vector<int> v){
    if(v.empty()) return NULL;
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;

    for(int i = 1; i < v.size(); i++){
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

// Utility: print list
void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> v1 = {2, 4, 3}; // represents 342
    vector<int> v2 = {5, 6, 4}; // represents 465

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}