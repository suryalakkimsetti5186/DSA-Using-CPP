#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution1: Using HashMap
class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        unordered_map<int,int> mp;
        for(ListNode* q = head; q; q = q->next)
            mp[q->val]++;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(ListNode* q = head; q; q = q->next){
            if(mp[q->val] == 1){
                temp->next = q;
                temp = temp->next;
            }
        }
        temp->next = NULL;

        return dummy->next;
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

    Solution1 obj;
    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates:\n";
    printList(head);

    return 0;
}