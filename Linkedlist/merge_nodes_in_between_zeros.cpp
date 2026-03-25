#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        ListNode *q = head->next, *p = temp;

        int sum = 0;

        while(q != NULL){
            if(q->val != 0){
                sum += q->val;
            } else {
                q->val = sum;
                p->next = q;
                p = p->next;
                sum = 0;
            }
            q = q->next;
        }

        p->next = NULL;   // important
        return temp->next;
    }
};

// Create list
ListNode* createList(vector<int> &arr) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int x : arr) {
        if (!head) head = tail = new ListNode(x);
        else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }
    return head;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {0,3,1,0,4,5,2,0};

    ListNode* head = createList(arr);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.mergeNodes(head);

    cout << "Merged: ";
    printList(head);

    return 0;
}