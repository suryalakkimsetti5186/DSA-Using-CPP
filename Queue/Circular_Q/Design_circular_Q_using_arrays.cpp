#include <iostream>
using namespace std;

/*
Circular Queue using Array

Description:
Implements a fixed-size circular queue using array.
Uses modulo arithmetic to maintain circular nature.

All operations are O(1)
*/

class MyCircularQueue {
public:
    int *arr;
    int front;
    int size;
    int cap;

    MyCircularQueue(int k) {
        cap = k;
        arr = new int[cap];
        front = 0;
        size = 0;
    }

    bool enQueue(int value) {
        if (size == cap) return false;

        int rear = (front + size) % cap;
        arr[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (size == 0) return false;

        front = (front + 1) % cap;
        size--;
        return true;
    }

    int Front() {
        if (size == 0) return -1;
        return arr[front];
    }

    int Rear() {
        if (size == 0) return -1;

        int rear = (front + size - 1) % cap;
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
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