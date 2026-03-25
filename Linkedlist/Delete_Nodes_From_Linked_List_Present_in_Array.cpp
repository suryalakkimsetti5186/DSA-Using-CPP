#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (st.count(curr->val)) {
                prev->next = curr->next;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

// Helper function to create linked list
ListNode* createList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    vector<int> nums = {2, 4};              // values to remove
    vector<int> listVals = {1, 2, 3, 4, 5}; // linked list

    ListNode* head = createList(listVals);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.modifiedList(nums, head);

    cout << "Modified List:\n";
    printList(head);

    return 0;
}