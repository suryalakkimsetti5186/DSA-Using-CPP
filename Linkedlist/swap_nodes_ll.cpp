#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next != NULL && prev->next->next != NULL){
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy->next;
    }
};

// function to print list
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // create list: 1->2->3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj;
    head = obj.swapPairs(head);

    printList(head);

    return 0;
}