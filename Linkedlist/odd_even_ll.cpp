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
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL || head->next==NULL)
            return head;

        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* evenHead = q;

        while(q != NULL && q->next != NULL){
            p->next = q->next;
            p = p->next;

            q->next = p->next;
            q = q->next;
        }

        p->next = evenHead;

        return head;
    }
};

void printList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    head = obj.oddEvenList(head);

    printList(head);

    return 0;
}