#include <iostream>
#include <string>
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        string s="";
        ListNode *q=head;

        for(;q!=NULL;q=q->next) 
            s.push_back(q->val + '0');

        int i=0,j=s.size()-1;

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;

    if(obj.isPalindrome(head))
        cout << "Palindrome Linked List";
    else
        cout << "Not a Palindrome";

    return 0;
}