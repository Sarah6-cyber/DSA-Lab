#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for (int i=0; i<size-1; i++){
        int smallestIndex=i; //assuming first element is smallest and sorted
        for (int j=i+1; j<size; j++){
            if (arr[j]<arr[smallestIndex]){
                smallestIndex=j;
            }
        }
        //swapping
        int temp=arr[smallestIndex];
        arr[smallestIndex]=arr[i];
        arr[i]=temp;
    }
    //printing sorted array
    for (int k=0; k<size; k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

int interpolationSearch(int sorted[], int size, int key){
    int low=0;
    int high=size-1;
    //while key in range and low high dont cross each other
    while(low<=high && key>=sorted[low] && key<=sorted[high]){
        if (low==high){
            if (sorted[low]==key){
                return low; //return pos of key if found
            }
            return -1;
        }
        int pos=low+((key-sorted[low])*(high-low))/(sorted[high]-sorted[low]);
        if (sorted[pos]==key){
            return pos; 
        }
        if (sorted[pos]<key){
            low=pos+1; //update low
        }
        else {
            high=pos-1;//update high
        }
    }
    return -1; //if not founs return -1
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
    selectionSort(arr,size);
    int result=interpolationSearch(arr,size,key);
    if (result!=-1){
        cout<<"key found at position: "<<result<<endl;
    }
    else {
        cout<<"key not found in array"<<endl;
    }
    delete [] arr;
    return 0;
}