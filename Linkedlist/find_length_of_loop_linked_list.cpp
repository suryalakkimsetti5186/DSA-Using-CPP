#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        int c=0,a=0;
        ListNode *p=head,*q=head;
        while(q!=NULL && q->next!=NULL){
            p=p->next;
            q=q->next->next;
            if(p==q) {
                a=1;
                break;
            }
        }
        if(!a) return 0;

        q=q->next;
        c=1;
        while(p!=q){
            q=q->next;
            c++;
        }
        return c;
    }
};

int main() {
    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating loop (5 -> 3)
    fifth->next = third;

    Solution obj;
    cout << "Length of loop: " << obj.findLengthOfLoop(head) << endl;

    return 0;
}