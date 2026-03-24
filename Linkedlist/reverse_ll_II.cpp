#include <iostream>
using namespace std;

// Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // move prev to (left-1)
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* q = NULL;

        // reverse sublist
        for(int i = left; i <= right; i++){
            ListNode* r = curr->next;
            curr->next = q;
            q = curr;
            curr = r;
        }

        // reconnect
        prev->next->next = curr;
        prev->next = q;

        return dummy->next;
    }
};

// 🔹 Print function
void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // 🔹 Create list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    cout << "Original List: ";
    printList(head);

    Solution obj;
    ListNode* newHead = obj.reverseBetween(head, left, right);

    cout << "Modified List: ";
    printList(newHead);

    return 0;
}