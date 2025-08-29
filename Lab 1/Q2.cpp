#include<iostream>
using namespace std;

class Exam{ 
    string *student_name; //pointer to observe shallow copy
    string exam_date;
    float score;
    public:
    Exam(){ //default constructor
        student_name=new string(" "); 
        score=0.0;
        exam_date=" ";
    }
    //setters for each attribute
    void setName(const string &name){
        *student_name=name;
    }
    void setDate(string date){
        exam_date=date;
    }
    void setScore(float s){
        score=s;
    }
    void printDetails(){ //method to print Exam details
        cout<<"----Exam Details-----"<<endl;
        cout<<"Student name: "<<*student_name<<endl;
        cout<<"Exam date: "<<exam_date<<endl;
        cout<<"Score: "<<score<<endl;
    }
    ~Exam(){ //destructor to free memory
        delete student_name;
        cout<<"exam destroyed"<<endl;
    }
};

int main(){
    Exam ex1;
    ex1.setName("sara");
    ex1.setDate("19-08-2025");
    ex1.setScore(28);
    Exam ex2=ex1; //using compiler generated copy constructor (shallow copy)
    ex1.printDetails();
    ex2.printDetails();
    //change score
    ex1.setName("amna");
    cout<<"after changing student name for exam 1"<<endl;
    ex1.printDetails();
    ex2.printDetails();
    return 0;
}