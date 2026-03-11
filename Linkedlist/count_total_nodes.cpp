#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=NULL;
    }
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};
class create{
    public:
    Node *head;
    create(){
        head=NULL;
    }
    void creat(int val){
    Node *q=new Node(val);
    if(head==NULL) head=q;
    else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next; 
            }
            temp->next = q; 
    }
}
   int print(){
       Node* q=head;
       int c=0;
        while(q!=NULL){
            cout << q->data << "\t";
            c++;
            q=q->next;
        }
        return c;
    }
};
int main(){
    create head;
    int v;
    do{
        int a;
        cout << "enetr data";
        cin >> a;
        head.creat(a);
        cout << "enter(0 or 1) if you need next node";
        cin >> v;
    }while(v==0 || v==1);
    cout << "\ntotal no.of nodes are=" << head.print();
}