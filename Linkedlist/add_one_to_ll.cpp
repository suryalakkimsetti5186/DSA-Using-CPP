#include <bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverseList(head);

        ListNode* curr = head;
        int carry = 1;

        while(curr != NULL) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if(carry == 0) break;

            if(curr->next == NULL && carry) {
                curr->next = new ListNode(carry);
                break;
            }

            curr = curr->next;
        }

        head = reverseList(head);
        return head;
    }
};

// Utility: print list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility: create list from vector
ListNode* createList(vector<int> v) {
    if(v.empty()) return NULL;
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;

    for(int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }

    return head;
}

int main() {
    vector<int> v = {9, 9, 9};  // change input here

    ListNode* head = createList(v);

    cout << "Original: ";
    printList(head);

    Solution obj;
    head = obj.addOne(head);

    cout << "After +1: ";
    printList(head);

    return 0;
}