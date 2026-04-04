// File: flatten_linked_list.cpp
// Description: Flatten a linked list with next and child pointers into a single sorted list using child pointers.

#include <iostream>
using namespace std;

// Definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(int data) {
        val = data;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;

        ListNode* result;

        if (a->val < b->val) {
            result = a;
            result->child = merge(a->child, b);
        } else {
            result = b;
            result->child = merge(a, b->child);
        }

        result->next = NULL;
        return result;
    }

    ListNode* flattenLinkedList(ListNode* &head) {
        if (!head || !head->next)
            return head;

        head->next = flattenLinkedList(head->next);
        head = merge(head, head->next);

        return head;
    }
};

// Utility to print flattened list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {

    /*
        Creating example:
        3 -> 2 -> 1 -> 4 -> 5
        |    |    |    |    |
        N   10    7    9    6
                 |         |
                11         8
                 |
                12
    */

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // child connections
    head->next->child = new ListNode(10);

    head->next->next->child = new ListNode(7);
    head->next->next->child->child = new ListNode(11);
    head->next->next->child->child->child = new ListNode(12);

    head->next->next->next->child = new ListNode(9);

    head->next->next->next->next->child = new ListNode(6);
    head->next->next->next->next->child->child = new ListNode(8);

    Solution obj;
    head = obj.flattenLinkedList(head);

    cout << "Flattened List: ";
    printList(head);

    return 0;
}