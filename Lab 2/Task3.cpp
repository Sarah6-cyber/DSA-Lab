#include<iostream>
using namespace std;

int main(){
    int ***marks; //storing marks 
    int departments, total=0, sum=0;
    int low=INT_MAX; //assuming low a higher number
    int high=INT_MIN; //assuming high a lower number

    cout<<"enter number of departments in university"<<endl;
    cin>>departments;
    int *students=new int[departments]; 
    marks=new int**[departments]; //allocating rows (depts)
    double *avg=new double[departments]; //storing avg marks per dept
    int *highest=new int[departments];
    int *lowest=new int[departments]; //storing lowest and highest marks per dept

    cout<<"enter number of students for each department"<<endl;
    for (int i=0; i<departments; i++){
        cout<<"department "<<i+1<<": ";
        cin>>students[i];
        marks[i]=new int*[students[i]]; //allocating columns (students per dept)
        for (int j=0; j<students[i]; j++){
            marks[i][j]=new int[5];
        }
    }

    cout<<"enter marks for every student in each dept"<<endl;
    for (int i=0; i<departments; i++){
        int sum=0, total=0;
        int high=INT_MIN, low=INT_MAX;
        cout<<"-------Department "<<i+1<<"-------"<<endl;
        for (int j=0; j<students[i]; j++){
            cout<<"Student "<<j+1<<": "<<endl;
            for (int k=0; k<5; k++){
                cout<<"Subject "<<k+1<<": ";
                cin>>marks[i][j][k];
                if (marks[i][j][k]>high){ //comparing for highest marks
                    high=marks[i][j][k];
                }
                if (marks[i][j][k]<low){ //comparing for lowest marks
                    low=marks[i][j][k];
                }
                sum+=marks[i][j][k]; //sum of all marks scored by students in a dept
                total++; //total marks per dept
            }
            cout<<endl;
        }
        avg[i]=(double)sum/total; //avg per dept
        highest[i]=high; //highest per dept
        lowest[i]=low; //l`owest per dept
        cout<<endl;
    }
    cout<<"-----Average marks per dept---------"<<endl;
    for (int i=0; i<departments; i++){ //print average per dept
        cout<<"department "<<i+1<<": "<<avg[i]<<endl;
    }
    cout<<"-----Highest marks per dept---------"<<endl; 
    for (int i=0; i<departments; i++){ //print highest marks per dept
        cout<<"department "<<i+1<<": "<<highest[i]<<endl;
    }
    cout<<"-----Lowest marks per dept---------"<<endl;
    for (int i=0; i<departments; i++){ //print lowest marks per dept
        cout<<"department "<<i+1<<": "<<lowest[i]<<endl;
    }
    return 0;
}