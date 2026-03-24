#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* prev;
    Node* next;
    Node(int data1){
        data=data1;
        prev=NULL;
        next=NULL;
    }
};
class create{
    public:
    Node* head;
    create(){
        head=NULL;
    }
    Node * insert(){
        int k;
        int a;
        cout << "enter data";
        cin  >> a;
        Node *q=new Node(a);
        head=q;
        do{
        int x;
        cout <<  "enter data value for node";
        cin >> x;
        Node *temp=new Node(x);
        q->next=temp;
        temp->prev=q;
        q=temp;
        cout << "enter (0 or 1) to insert next node";
        cin >> k;
    }while(k==0 || k==1);
    return head;
    }
    void print(Node *head){
        Node* q=head,*temp;
        while(q!=NULL){
            cout << q->data << "\t";
            temp=q;
            q=q->next;
        }
    }
    Node * reverse(Node *head){
        Node*p=head;
        while(p!=NULL){
            Node *q=p->next;
            p->next=p->prev;
            p->prev=q;
            head=p;
            p=q; 
        }
        return head;
    }
};
int main(){
    create c;
    int k;
    Node *head;
    head=c.insert();
    //cout << "\n the data values are:";
    c.print(head);
    head=c.reverse(head);
    cout << "\nafter the reversing of nodes\n";
    c.print(head);
}