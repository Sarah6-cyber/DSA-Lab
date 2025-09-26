#include<iostream> 
using namespace std;

class Node{
    public:
    int data; 
    Node *next; //points to next node
    Node(int val){ //constructor to initialize node
        data=val;
        next=nullptr; //initially points to null
    }
};

class Singly{
    Node *head; 
    Node *tail;
    public:
    Singly(){
        head=nullptr;
        tail=nullptr;
    }
    void addIntegerInList(int val){ //making a list of integers
        Node *newNode=new Node(val); 
        Node *temp=head; //for traversal without changing head
        if (head==nullptr){ //if list empty
            head=newNode;
            return;
        }
        while (temp->next!=nullptr){ //if list not empty 
            temp=temp->next; //find last node
        }
        //node added at the end of the list to ensure order
        temp->next=newNode; 
        newNode->next=nullptr;
    }
    void seperateEvenOdd(){
        Node *evenHead=nullptr, *lastEven=nullptr;
        Node *oddHead=nullptr, *lastOdd=nullptr;
        Node *temp=head; //for traversal
        while(temp!=nullptr){ //traverse till list ends
            Node *nextNode=temp->next; //save the next node in traversal
            temp->next=nullptr; //break link from prev list
            if (temp->data%2==0){ //if even
                if (evenHead==nullptr){ //if list empty
                    evenHead=temp;
                }
                else{ //if list not empty
                    Node *currEven=evenHead; //pointer for traversal through even list 
                    while(currEven->next!=nullptr){
                        currEven=currEven->next; //find last node in list
                    }
                    currEven->next=temp; //node added to even list 
                }
            }
            else if(temp->data%2!=0){ //is odd
                if (oddHead==nullptr){ //if list empty
                    oddHead=temp;
                }           
                else{ //if list not empty
                    Node *currOdd=oddHead; //pointer for traversal through odd list
                    while(currOdd->next!=nullptr){ 
                        currOdd=currOdd->next; //find last node in odd list
                    }
                    currOdd->next=temp; //node added to odd list
                }     
            }
            temp=nextNode; //move to next node
        }
        //connecting even and odd list
        if (evenHead==nullptr){ //if only odd integers
            head=oddHead;
            return;
        }
        else if (oddHead==nullptr){ //if only even integers
            head=evenHead;
            return;
        }
        else { //both even and odd
            lastEven=evenHead; //for traversal through even list
            while (lastEven->next!=nullptr){ 
                lastEven=lastEven->next; //find last node of even list
            }
            lastOdd=oddHead; //for traversal through odd list
            while (lastOdd->next!=nullptr){
                lastOdd=lastOdd->next; //find last node of odd list
            }
            lastEven->next=oddHead; //connect last node of even list to first node of odd list
            head=evenHead; //change head to even head for display
        }
    }    
    void display(){
        Node *temp=head; //for traversal
        while (temp!=nullptr){
            cout<<temp->data<<" -> "; //print values of the list
            temp=temp->next; //move to next node
        }
        cout<<"NULL"<<endl; //prints null at the end of list (dramatic effect)
    }
};

int main(){
    Singly s1;
    s1.addIntegerInList(17);
    s1.addIntegerInList(15);
    s1.addIntegerInList(8);
    s1.addIntegerInList(12);
    s1.addIntegerInList(10);
    s1.addIntegerInList(5);
    s1.addIntegerInList(4);
    s1.addIntegerInList(1);
    s1.addIntegerInList(7);
    s1.addIntegerInList(6);
    s1.display(); //display original list
    s1.seperateEvenOdd();
    s1.display(); //display ordered list
    return 0;
}