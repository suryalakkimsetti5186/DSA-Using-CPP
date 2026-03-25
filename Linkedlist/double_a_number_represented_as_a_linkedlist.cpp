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
    ListNode* reverse(ListNode* head) {
        ListNode *p = head, *q = NULL, *r = NULL;
        while (p != NULL) {
            r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        return q;
    }

    ListNode* doubleIt(ListNode* head) {
        if (head == NULL) return head;

        ListNode* first = reverse(head);
        int carry = 0;

        ListNode *temp = first, *p = NULL;

        while (temp) {
            int product = temp->val * 2 + carry;
            carry = product / 10;
            temp->val = product % 10;

            p = temp;
            temp = temp->next;
        }

        if (carry) p->next = new ListNode(carry);

        return reverse(first);
    }
};

// Helper: create linked list
ListNode* createList(vector<int> &arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper: print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 8, 9}; // represents 189
    ListNode* head = createList(arr);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.doubleIt(head);

    cout << "After doubling: ";
    printList(head);

    return 0;
}