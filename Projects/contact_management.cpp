#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
    string number;
    Node* next;

    Node(string n,string num){
        name=n;
        number=num;
        next=NULL;
    }
};

class ContactManager{

public:
    Node* head;

    ContactManager(){
        head=NULL;
    }

    void insert(){

        string name,number;

        cout<<"Enter name : ";
        cin>>name;

        cout<<"Enter number : ";
        cin>>number;

        Node* temp=new Node(name,number);

        if(head==NULL){
            head=temp;
            return;
        }

        Node* q=head;

        while(q->next!=NULL)
            q=q->next;

        q->next=temp;

        cout<<"Contact added successfully\n";
    }

    void display(){

        if(head==NULL){
            cout<<"No contacts available\n";
            return;
        }

        Node* q=head;

        cout<<"\n----- CONTACT LIST -----\n";

        while(q!=NULL){

            cout<<"Name   : "<<q->name<<endl;
            cout<<"Number : "<<q->number<<endl;
            cout<<"------------------------\n";

            q=q->next;
        }
    }

    void search(){

        if(head==NULL){
            cout<<"No contacts available\n";
            return;
        }

        string name;
        cout<<"Enter name to search : ";
        cin>>name;

        Node* q=head;

        while(q!=NULL){

            if(q->name==name){
                cout<<"\nContact Found\n";
                cout<<"Name   : "<<q->name<<endl;
                cout<<"Number : "<<q->number<<endl;
                return;
            }

            q=q->next;
        }

        cout<<"Contact not found\n";
    }

    void deleteContact(){

        if(head==NULL){
            cout<<"No contacts available\n";
            return;
        }

        string name;
        cout<<"Enter name to delete : ";
        cin>>name;

        Node* q=head;
        Node* prev=NULL;

        while(q!=NULL){

            if(q->name==name){

                if(prev==NULL)
                    head=q->next;
                else
                    prev->next=q->next;

                delete q;

                cout<<"Contact deleted\n";
                return;
            }

            prev=q;
            q=q->next;
        }

        cout<<"Contact not found\n";
    }
};

int main(){

    ContactManager cm;

    int choice;

    while(true){

        cout<<"\n------ CONTACT MANAGEMENT SYSTEM ------\n";
        cout<<"1. Insert Contact\n";
        cout<<"2. Display Contacts\n";
        cout<<"3. Search Contact\n";
        cout<<"4. Delete Contact\n";
        cout<<"5. Exit\n";

        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice){

            case 1:
                cm.insert();
                break;

            case 2:
                cm.display();
                break;

            case 3:
                cm.search();
                break;

            case 4:
                cm.deleteContact();
                break;

            case 5:
                exit(0);

            default:
                cout<<"Enter valid choice\n";
        }
    }
}