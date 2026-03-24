#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}
};

// insert at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) return newNode;

    ListNode* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// print result pairs
void printPairs(vector<vector<int>> &v) {
    for (auto &pair : v) {
        cout << "(" << pair[0] << ", " << pair[1] << ")\n";
    }
}

// your function
vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
    ListNode *p = head, *q = head;

    if (head == NULL) return {};

    while (q->next != NULL) q = q->next;

    vector<vector<int>> v;

    while (p != NULL && q != NULL && p != q && q->next != p) {
        vector<int> l;
        int sum = p->val + q->val;

        if (sum == target) {
            l.push_back(p->val);
            l.push_back(q->val);
            p = p->next;
            q = q->prev;
        }
        else if (sum < target) p = p->next;
        else q = q->prev;

        if (!l.empty()) v.push_back(l);
    }

    return v;
}

int main() {
    ListNode* head = NULL;

    // create sorted DLL
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    int target = 5;

    vector<vector<int>> result = findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ":\n";
    printPairs(result);

    return 0;
}