/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode *p,*q;
     p=l1;
     q=l2;
     int carry=0;
     ListNode *head=new ListNode(-1);
     ListNode *dummy=head;
     while(p!=NULL || q!=NULL || carry){
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum=(x+y+carry);
        carry=sum/10;
        int c=sum%10;
        ListNode *temp=new ListNode(c);
        dummy->next=temp;
        dummy=dummy->next;
        if(p) p=p->next;
        if(q) q=q->next;
     }
        return  head->next;  
    }
};