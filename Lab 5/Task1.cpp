#include<iostream>
using namespace std;

bool findSubset(int arr[], int n, int index, int target){
    //base cases
    if (target==0){
        return true;
    }
    if (index==n){
        return false;
    }
    //recursive cases
    //value>target (so you skip that value and move to next)
    if (arr[index]>target){
        return findSubset(arr,n,index+1,target);
    }
    //value<target (either include or exclude to reach every possible combination)
    return findSubset(arr,n,index+1,target-arr[index]) || findSubset(arr,n,index+1,target);
}

void printArr(int arr[], int size){
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={3,34,4,12,5,2};
    int sum=9;
    int size=sizeof(arr)/sizeof(int);
    bool result=findSubset(arr,size,0,sum);
    printArr(arr,size);
    if (result){
        cout<<"true! subset with sum "<<sum<<" found."<<endl;
    }
    else {
        cout<<"false! subset with sum "<<sum<<" not found."<<endl;
    }
    return 0;
}