#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for (int i=1; i<size; ++i){ 
        int key=arr[i]; //assuming first element is sorted
        int j=i-1; //usnorted elements indexing by j
        while (j>=0 &&arr[j]>key){ 
            arr[j+1]=arr[j]; //swap
            j--;
        }
        arr[j+1]=key; //update key
    }
    //printing sorted list
    for (int k=0; k<size; k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

int binarySearch(int sorted[], int size, int key){
    int low=0;
    int high=size-1;
    while (high>=low){ 
        int mid=(high+low)/2; //calculating mid
        if (key==sorted[mid]){
            return mid; //returning pos of key if found
        }
        else if (key<sorted[mid]){
            high=mid-1; //new high
        }
        else {
            low=mid+1; //new low
        }
    }
    return -1;
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
    insertionSort(arr,size);
    int result=binarySearch(arr,size,key);
    if (result!=-1){
        cout<<"key found at position: "<<result<<endl;
    }
    else {
        cout<<"key not found in array"<<endl;
    }
    delete [] arr;
    return 0;
}