#include <bits/stdc++.h>
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
    ListNode *ms(ListNode *head1, ListNode *head2){
        ListNode *p = head1, *q = head2;
        ListNode *dummy = new ListNode(-1);
        ListNode *t = dummy;

        while(p != NULL && q != NULL){
            if(p->val < q->val){
                t->next = p;
                p = p->next;
            } else {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }

        if(p != NULL) t->next = p;
        else t->next = q;

        return dummy->next;
    }

    ListNode *middle(ListNode *head){
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *head){
        if(head == NULL || head->next == NULL) return head;

        ListNode *mid = middle(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        ListNode *p = merge(left);
        ListNode *q = merge(right);

        return ms(p, q);
    }

    ListNode* sortList(ListNode* head) {
        return merge(head);
    }
};

// Helper to insert node
ListNode* insert(ListNode* head, int val){
    if(!head) return new ListNode(val);
    ListNode* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    return head;
}

// Helper to print list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = NULL;

    // Example input
    vector<int> arr = {4, 2, 1, 3};

    for(int x : arr){
        head = insert(head, x);
    }

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

