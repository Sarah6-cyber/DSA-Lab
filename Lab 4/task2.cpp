#include<iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *next; 
    Node *prev; 
    Node(int val){ //constructor
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};

class circularDoublyList{
    Node *head; 
    Node *tail;
    public:
    circularDoublyList(){ //constructor
        head=nullptr;
        tail=nullptr;
    }
    void insertFirst(int val){ //insert node at first
        Node *newNode=new Node(val);
        if (head==nullptr){ //if list empty
            head=newNode;
            tail=newNode;
            head->next=head;
            head->prev=head;
        }
        else{
            newNode->next=head; 
            newNode->prev=tail;
            tail->next=newNode;
            head->prev=newNode;
            head=newNode; //move head to newNode
        }
    }
    void insertLast(int val){ //inserting at last
        Node *newNode=new Node(val);
        if (head==nullptr){ //if list empty
            head=newNode;
            tail=newNode;
            head->next=head;
            head->prev=head;
        }
        else{ //if not empty
            newNode->next=head; //linking newNode to head
            newNode->prev=tail; //linking newNode to previous tail
            tail->next=newNode; //tail points to newNode
            head->prev=newNode; //head’s prev updated
            tail=newNode; //move tail to newNode
        }
    }
    void insertAtPos(int val,int pos){ //inserting node at any given pos
        if (pos==1){ //if inserting at first
            insertFirst(val);
            return;
        }
        Node *newNode=new Node(val);
        Node *curr=head;
        for (int i=1;i<pos-1;i++){ //move till pos-1
            curr=curr->next;
            if (curr==head){ //if pos>length
                cout<<"Invalid position"<<endl;
                return;
            }
        }
        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
        if (curr==tail){ //if inserted at last
            tail=newNode;
        }
    }
    void deleteAtPos(int pos){ //delete at any given pos
        if (head==nullptr){ //if empty
            cout<<"List empty"<<endl;
            return;
        }
        if (pos==1){ //delete first node
            Node *temp=head;
            if (head==tail){ //only one node
                head=nullptr;
                tail=nullptr;
            }
            else{
                head=head->next;
                head->prev=tail;
                tail->next=head;
            }
            delete temp;
            return;
        }
        Node *curr=head;
        for (int i=1;i<pos;i++){ 
            curr=curr->next;
            if (curr==head){ //if pos > length
                cout<<"Invalid position"<<endl;
                return;
            }
        }
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        if (curr==tail){ //if deleting last
            tail=curr->prev;
        }
        delete curr;
    }
    void printList(){ //printing the list
        if (head==nullptr){ //if empty
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        } while(temp!=head);
        cout<<endl;
    }
};

int main(){
    circularDoublyList cl;
    cout<<"Insert at end: "<<endl;
    cl.insertLast(10);
    cl.printList();
    cout<<"Insert at beginning: "<<endl;
    cl.insertFirst(5);
    cl.printList();
    cout<<"Insert at position 3: "<<endl;
    cl.insertAtPos(15,3);
    cl.printList();
    cout<<"Delete node at position 2: "<<endl;
    cl.deleteAtPos(2);
    cl.printList();
    return 0;
}
