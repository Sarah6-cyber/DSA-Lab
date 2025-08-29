#include<iostream> //header file
using namespace std; //to avoid using st::

class BankAccount{ // bank acc created 
    int balance; //attribute
    public:
    BankAccount(){ //default constructor
        balance=0;
        cout<<"Initial balance: "<<balance<<endl;
    }
    BankAccount(int bal){ //parameterized constructor
        balance=bal; 
        cout<<"Initial balance: "<<balance<<endl;
    }
    BankAccount(const BankAccount &acc){ //copy constructor
        balance=acc.balance-200;
        cout<<"balance of new account: "<<balance<<endl;
        cout<<"balance of old account: "<<acc.balance<<endl;
    }
};

int main(){
    BankAccount account1; //using default constructor
    BankAccount account2(1000); //using parameterized constructor
    BankAccount account3(account2); //using copy constructor
    return 0;
}