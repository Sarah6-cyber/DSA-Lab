#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

class circularList{ //singly circular 
    Node *head;
    Node *tail;
    public:
    circularList(){ //constructor
        head=nullptr;
        tail=nullptr;
    }
    void insertFirst(int val){ //inserting node at first pos
        Node *newNode = new Node(val); //creating new node
        if (head==nullptr){ //check if list empty
            head=newNode;
            tail=newNode;
            tail->next=head;
        }
        else {   //if ,list not empty
            newNode->next=head; 
            head=newNode;
            tail->next=head; //maintaining circular
        }
    }
    void insertLast(int val){ //inserting at last pos
        Node *newNode = new Node(val);
        if (head==nullptr){ //if list empty
            head=newNode;
            tail=newNode;
            tail->next=head;
        }
        else { //if not empty
            newNode->next=head; //maintaining circular list
            tail->next=newNode; 
            tail=newNode;
        }
    }
    void insertInBetween(int val, int pos){ //inserting at any given pos
        Node *newNode = new Node(val);
        if (head==nullptr){ //if list empty
            insertFirst(val);
            return;
        }
        else if (pos==1){ //if inserting at first pos
            insertFirst(val);
            return;
        }
        else { //if inserting elseWhere
            Node *prev=head; //points to prev node
            Node *curr=head; //points to curr node
            for (int i=1; i<pos; i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=newNode;
            newNode->next=curr;
        }
    }
    void deleteFirst(){ 
        if (head==nullptr){ //check if list empty
            return;
        }
        else { //if list not empty
            Node *temp=head;
            tail->next=head->next;
            head=temp->next;
            delete temp;
        }
    }
    void deleteLast(){
        //empty list
        if (head==nullptr){
            return;
        }
        //one node in list
        else if (head==tail){
            delete head;
            tail=nullptr;
            head=nullptr;
            return;
        }
        //multiple nodes in list
        else {
            Node *temp=head;
            Node *tempTail=tail;
            while (temp->next!=tail){
                temp=temp->next;
            }
            temp->next=head;
            tail=temp;
            delete tempTail;
        }
    }
    void deleteInBetween(int pos){ //deleting node at specific pos
        if (head==nullptr){ //if list empty
            return;
        }
        else if(pos==1){ //if deleting first node
            deleteFirst();
        }
        else { //if any other pos
            Node *prev=head;
            Node *curr=head;
            for (int i=1; i<pos; i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            delete curr;
        }
    }
    void printList(){ //printing list
        Node *temp=head; //temp to avoid head loss
        if (head==nullptr){
            cout<<"list is empty"<<endl;
            return;
        }
        //circular list, hence using do while loop
        do { 
            cout<<temp->data<<" ";
            temp=temp->next;
        } while (temp!=head); //till temp points back to head
        cout<<endl;
    }
};  

int main(){
    circularList cl;
    cout<<"insert at first: "<<endl;
    cl.insertFirst(2);
    cl.printList();
    cout<<"insert at last: "<<endl;
    cl.insertLast(4);
    cl.printList();
    cout<<"insert at pos 2: "<<endl;
    cl.insertInBetween(3,2);
    cl.printList();
    cout<<"delete node at pos 2: "<<endl;
    cl.deleteInBetween(2);
    cl.printList();
    cout<<"delete first node: "<<endl;
    cl.deleteFirst();
    cl.printList();
    return 0;
}