#include <iostream>
using namespace std;

int main(){
    int students=5, subjects=4;
    int** marks=new int*[students]; //dma for every student
    for (int i=0; i<students; i++){ //dma for every subject of each student
        marks[i]=new int[subjects];
    }
    int totalArr[5]={0}; //to store total of each student      
    float avgArr[4]={0.0f};   //to store average of each subject
    cout<<"Enter marks for each student in each subject: "<<endl; 
    for (int i=0; i<students; i++){  //user input
        cout<<"Student "<<i+1<< ": "<<endl;
        for (int j=0; j<subjects; j++){
            cout<<"Subject "<<j+1<< ": ";
            cin>>marks[i][j];
            totalArr[i]+=marks[i][j];    
            avgArr[j]+=marks[i][j];  
        }
        cout<<endl;
    }
    cout<<"Total marks of each student: "<<endl;
    for (int i=0; i<students; i++){ //total print
        cout<<"Student "<<i+1<<": "<<totalArr[i]<<endl;
    }
    cout<<"Average marks of each subject: "<<endl;
    for (int j=0; j<subjects; j++){ //average print
        cout<<"Subject "<<j+1<<": "<<avgArr[j]/students<<endl;
    }
    int topInd=0;
    for (int i=1; i<students; i++){ //calculating highest
        if (totalArr[i]>totalArr[topInd]){
            topInd=i;
        }
    }
    cout<<"Topper student "<<topInd+1<<" with total marks "<<totalArr[topInd]<<endl; //print highest
    delete[] marks; //free memory
    return 0;
}

    