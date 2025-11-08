#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for (int i=0; i<size-1; i++){
        bool isSwap=false; //to check if array sorting complete
        for (int j=0; j<size-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSwap=true;
            }
        }
        if (!isSwap){ //is no swap means array sorted 
            break; //move out of loop
        }
    }
    for (int k=0; k<size; k++){ //printing sorted array
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

int linearSearch(int arr[], int size, int key){
    int pos; //pos to return
    for (int i=0; i<size; i++){
        if (arr[i]==key){
            pos=i;
            return pos;
        }
    }
    return -1; //if key not found
}

int main(){
    int *arr;
    int size, key;
    cout<<"enter size of array: "<<endl;
    cin>>size;
    arr=new int[size];
    cout<<"enter array elements"<<endl;
    for (int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"enter key: "<<endl;
    cin>>key;
    cout<<"sorted array: "<<endl;
    bubbleSort(arr,size);
    int result=linearSearch(arr,size,key);
    if (result!=-1){
        cout<<"key found at position: "<<result<<endl;
    }
    else {
        cout<<"key not found in array"<<endl;
    }
    delete [] arr;
    return 0;
}