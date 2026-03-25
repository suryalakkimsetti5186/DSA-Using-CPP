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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        unordered_map<int, ListNode*> mp;
        int prefix = 0;

        // First pass
        for (ListNode* q = temp; q; q = q->next) {
            prefix += q->val;
            mp[prefix] = q;
        }

        // Second pass
        prefix = 0;
        for (ListNode* q = temp; q; q = q->next) {
            prefix += q->val;
            q->next = mp[prefix]->next;
        }

        return temp->next;
    }
};

// Helper to create linked list
ListNode* createList(vector<int> &arr) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int x : arr) {
        if (!head) {
            head = tail = new ListNode(x);
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }
    return head;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, 1};

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.removeZeroSumSublists(head);

    cout << "After Removal: ";
    printList(head);

    return 0;
}