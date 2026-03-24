#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* u = new ListNode(X, head);
        head = u;
        return head;
    }
};

int main() {
    ListNode* head = nullptr;
    Solution s;
    head = s.insertAtHead(head, 5);
    head = s.insertAtHead(head, 10);
    head = s.insertAtHead(head, 20);

    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}