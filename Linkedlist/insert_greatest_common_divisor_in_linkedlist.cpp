#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Insert Greatest Common Divisors in Linked List

    Description:
    Given a singly linked list, insert a new node between every pair of adjacent nodes.
    The value of the new node should be the GCD of the adjacent nodes.

    Approach:
    - Traverse the linked list
    - For each pair (curr, curr->next):
        - Compute gcd(curr->val, curr->next->val)
        - Insert new node in between
    - Move to next original node

    Time Complexity: O(n * log(max(a, b)))
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* q = head;

        while(q && q->next){
            int x = q->val;
            int y = q->next->val;

            ListNode* temp = new ListNode(gcd(x, y));

            temp->next = q->next;
            q->next = temp;

            q = temp->next; // move to next original node
        }

        return head;
    }
};

// 🔹 Utility: Create list
ListNode* createList(vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// 🔹 Utility: Print list
void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🔹 MAIN FUNCTION
int main() {
    vector<int> arr = {18, 6, 10, 3};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.insertGreatestCommonDivisors(head);

    cout << "Modified List:\n";
    printList(head);

    return 0;
}