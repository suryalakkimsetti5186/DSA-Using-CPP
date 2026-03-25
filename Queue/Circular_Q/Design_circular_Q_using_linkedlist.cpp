#include <iostream>
using namespace std;

/*
Circular Queue using Circular Linked List

Description:
Implements a fixed-size circular queue using linked list.
Maintains circular connection where last node points to head.

Note:
Current implementation has O(n) for enQueue and Rear due to traversal.
*/

class MyCircularQueue {
public:
    struct Node {
        int val;
        Node* next;
    };

    int size, full;
    Node* head;

    MyCircularQueue(int k) {
        head = NULL;
        size = 0;
        full = k;
    }

    bool enQueue(int value) {
        if (size == full) return false;

        Node* temp = new Node();
        temp->val = value;

        if (size == 0) {
            head = temp;
            head->next = head;
            size++;
            return true;
        }

        Node* q = head;
        while (q->next != head) {
            q = q->next;
        }

        q->next = temp;
        temp->next = head;
        size++;
        return true;
    }

    bool deQueue() {
        if (size == 0) return false;

        if (size == 1) {
            delete head;
            head = NULL;
            size--;
            return true;
        }

        Node* q = head;
        while (q->next != head) {
            q = q->next;
        }

        Node* temp = head;
        head = head->next;
        q->next = head;

        delete temp;
        size--;
        return true;
    }

    int Front() {
        if (size == 0) return -1;
        return head->val;
    }

    int Rear() {
        if (size == 0) return -1;

        Node* q = head;
        while (q->next != head) {
            q = q->next;
        }
        return q->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == full;
    }
};

int main() {
    MyCircularQueue q(3);

    cout << "enQueue(1): " << q.enQueue(1) << endl;
    cout << "enQueue(2): " << q.enQueue(2) << endl;
    cout << "enQueue(3): " << q.enQueue(3) << endl;
    cout << "enQueue(4): " << q.enQueue(4) << endl; // should fail

    cout << "Rear: " << q.Rear() << endl;
    cout << "isFull: " << q.isFull() << endl;

    cout << "deQueue: " << q.deQueue() << endl;
    cout << "enQueue(4): " << q.enQueue(4) << endl;

    cout << "Rear: " << q.Rear() << endl;
    cout << "Front: " << q.Front() << endl;

    return 0;
}