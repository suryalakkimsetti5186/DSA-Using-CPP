#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Remove Nodes From Linked List

    Description:
    Given a singly linked list, remove every node that has a node 
    with a greater value anywhere to its right.

    Approach:
    1. Reverse the linked list
    2. Traverse while maintaining maximum value seen so far
    3. Remove nodes smaller than max
    4. Reverse the list again to restore order

    Time Complexity: O(n)
    Space Complexity: O(1)

    Author: Surya
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
    // Reverse linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // Main logic
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxi = INT_MIN;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            if(curr->val >= maxi){
                maxi = curr->val;
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }

        return reverse(head);
    }
};

// 🔹 Utility: Create linked list
ListNode* createList(vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// 🔹 Utility: Print linked list
void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🔹 MAIN FUNCTION
int main() {
    vector<int> arr = {5, 2, 13, 3, 8};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.removeNodes(head);

    cout << "Modified List:\n";
    printList(head);

    return 0;
}