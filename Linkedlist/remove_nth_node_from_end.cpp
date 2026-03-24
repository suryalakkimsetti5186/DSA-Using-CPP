#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++)
            fast = fast->next;

        if(fast == NULL)
            return head->next;

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // Create list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    printList(head);

    return 0;
}