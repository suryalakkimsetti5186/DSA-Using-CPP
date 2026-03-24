#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution2: Optimal
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while(head){
            if(head->next && head->val == head->next->val){
                int val = head->val;
                while(head && head->val == val){
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};

// Create list
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Print list
void printList(ListNode* head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// MAIN
int main() {
    vector<int> arr = {1,2,2,3,4,4,5};

    ListNode* head = createList(arr);

    cout << "Original:\n";
    printList(head);

    Solution2 obj;
    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates:\n";
    printList(head);

    return 0;
}