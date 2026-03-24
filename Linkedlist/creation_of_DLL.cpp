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
    void insert(int x){
        Node* q=new Node(x);
        //q->prev=NULL;
        if(head==NULL) head=q;
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=q;
            q->prev=temp;
        }
    }
    void print(){
        Node* q=head,*temp;
        while(q!=NULL){
            cout << q->data << "\t";
            temp=q;
            q=q->next;
        }
        cout << "\n";
        while(temp!=NULL){
            cout << temp->data << "\t";
            temp=temp->prev;
        }
    }
};
int main(){
    create c;
    int k;
    do{
        int x;
        cout <<  "enter data value for node";
        cin >> x;
        c.insert(x);
        cout << "enter (0 or 1) to insert next node";
        cin >> k;
    }while(k==0 || k==1);
    //cout << "\n the data values are:";
    c.print();
}