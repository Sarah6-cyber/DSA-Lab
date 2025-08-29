#include<iostream>
using namespace std;

class BoxButShallow{
    int *integer; //using pointer for integer
    public:
    BoxButShallow(){ //default constructor
        integer=new int;
    }
    void setInteger(int i){ //setter
        *integer=i;
    }
    int printInt(){ //printing stored integer in box obj
        return *integer;
    } 
    ~BoxButShallow(){ //destructor to free memory
        delete integer;
        cout<<"box destroyed"<<endl;
    }
};
class Box{
    int *integer; //using pointer for integer
    public:
    Box(){ //default constructor
        integer=new int;
    }
    void setInteger(int i){ //setter
        *integer=i;
    }
    int printInt(){ //printing stored integer in box obj
        return *integer;
    }
    Box(const Box &b){ //copy constructor
        integer=new int(*b.integer);
    }
    Box &operator=(const Box &b){ //copy assignment operator
        if (this!=&b){
            delete integer;
            integer=new int(*b.integer);
        }
        return *this;
    }
    ~Box(){ //destructor to free memory
        delete integer;
        cout<<"box destroyed"<<endl;
    }

};

int main(){
    //using compiler's copy constructor
    cout<<"----SHALLOW COPY DEMONSTRATION USING DEFAULT COPY CONSTRUCTOR--------"<<endl;
    cout<<endl;
    BoxButShallow box1;
    box1.setInteger(3);

    //checking copy constructor 
    cout<<"integer stored in box1: "<<box1.printInt()<<endl;
    BoxButShallow box2(box1);
    cout<<"copy constructor called"<<endl;
    cout<<"integer stored in box2: "<<box2.printInt()<<endl;
    box1.setInteger(4);
    cout<<"integer of box1 changed"<<endl;
    cout<<"integer stored in box1: "<<box1.printInt()<<endl;
    cout<<"integer stored in box2: "<<box2.printInt()<<endl;
    cout<<endl;

    //using my own copy constructor and copy assignment
    cout<<"----DEEP COPY DEMONSTRATION--------------"<<endl;
    cout<<endl;
    Box b1;
    b1.setInteger(3);

    //checking copy constructor 
    cout<<"integer stored in b1: "<<b1.printInt()<<endl;
    Box b2(b1);
    cout<<"copy constructor called"<<endl;
    cout<<"integer stored in b2: "<<b2.printInt()<<endl;
    b1.setInteger(4);
    cout<<"integer of b1 changed"<<endl;
    cout<<"integer stored in b1: "<<b1.printInt()<<endl;
    cout<<"integer stored in b2: "<<b2.printInt()<<endl;
    
    //checking copy assignment operator
    Box b3;
    b3=b1;
    cout<<endl;
    cout<<"copy assignment operator called"<<endl;
    cout<<"integer stored in b1: "<<b1.printInt()<<endl;
    cout<<"integer stored in b3: "<<b3.printInt()<<endl;
    b1.setInteger(5);
    cout<<"integer of b1 changed"<<endl;
    cout<<"integer stored in b1: "<<b1.printInt()<<endl;
    cout<<"integer stored in b3: "<<b3.printInt()<<endl;
    return 0;
}