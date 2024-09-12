#include <bits/stdc++.h>
using namespace std;
void printarray(int * arr,int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    
}
bool foundElement(int* arr,int size,int element){
    if(size==0)return false;
    else if(arr[0]==element)return true;
    return foundElement(arr+1,size-1,element);
}
bool binarySearchFound(int * arr,int low,int high,int element){
    int mid=low+(high-low)/2;
    if(low>high)return false;
    else if(arr[mid]==element)return true;
    else if(arr[mid]>element){
        high=mid-1;
        return binarySearchFound(arr,low,high,element);
    }else{
        low=mid+1;
        return binarySearchFound(arr,low,high,element);
    }
}
void selectionSort(int * arr, int size){
    if(size==1)return ;
    int miniIndex=0;
    for(int i=1;i<size;i++){
        if(arr[miniIndex]>arr[i]){
            miniIndex=i;
        }
    }
    swap(arr[0],arr[miniIndex]);
    selectionSort(arr+1,size-1);
}
void insertionSort(int * arr,int size,int i=1){
    if(i==size)return ;
    int j=i-1,key=arr[i];
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    insertionSort(arr,size,i+1);

}

void 
int main(){
    int a[]={2,1,8,4,6};
    int b[]={4,6,1,9,10,55,4,1,23,9,52};
    insertionSort(b,11);
    printarray(b,11);   
    // cout<<binarySearchFound(a,0,5,6)<<'\n';
    return 0;
}