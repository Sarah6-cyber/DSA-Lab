#include<iostream>
using namespace std;

void checkParenthesis(char arr[], int pos, int open, int closed, int n){
    //base case
    if (open==n && closed==n){
        arr[pos]='\0'; //end string
        cout<<arr<<endl;
        return;
    }
    //recursive cases
    if (open<n){
        arr[pos]='(';
        checkParenthesis(arr,pos+1,open+1,closed,n);
    }
    if (closed<open){
        arr[pos]=')';
        checkParenthesis(arr,pos+1,open,closed+1,n);
    }
}
void makeParenthesis(int n){
    char arr[2*n+1]; //make an arr for combination of parenthesis
    checkParenthesis(arr,0,0,0,n); //start generating possible combinations
}
int main(){
    int n=3;
    cout<<"Possible combinations of "<<n<<" paranthesis:"<<endl;
    makeParenthesis(n);
    return 0;
}