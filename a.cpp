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

void mergeArray(int * A,int s,int mid,int e){
    int p=s,q=mid+1;
    int Arr[e-s+1];
    int k=0;

   for(int i = s ;i <= e ;i++) {
    if(p > mid)      //checks if first part comes to an end or not .
       Arr[ k++ ] = A[ q++] ;

   else if ( q > e)   //checks if second part comes to an end or not
       Arr[ k++ ] = A[ p++ ];

   else if( A[ p ] < A[ q ])     //checks which part has smaller element.
      Arr[ k++ ] = A[ p++ ];

   else
      Arr[ k++ ] = A[ q++];
 }
  for (int p=0 ; p< k ;p ++) {
   /* Now the real array has elements in sorted manner including both 
        parts.*/
     A[ s++ ] = Arr[ p ] ;                          
  }
    
}
void mergeSort(int * arr,int s,int e){
    if(s>=e)return ;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    mergeArray(arr,s,mid,e);
}
//quick sort implementation 
//partition and then quicksort
//1.partition -> we take the first element and then find it's correct place ,also replace all the smaller elements to the left

//2.then we divide the array based on the pivotIndex ,and then apply quickSort again
int partition(int * arr,int s,int e){
    int pivot=arr[s],cnt=0;
    for (int i = s+1; i < e+1; i++)
    {
        if(pivot>arr[i])cnt++;
    }
    int pivotIndex=s+cnt;
    swap(arr[s],arr[pivotIndex]);
    int i=s,j=e;
    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>=pivot)
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
        
        
    }
    return pivotIndex;

    

}


void quickSort(int * arr,int s,int e){
    if(s>=e) return ;
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}


int main(){
    int a[]={2,1,8,4,6};
    int b[]={4,6,1,9,10,55,4,1,23,9,52};
    // insertionSort(b,11);
    // mergeSort(b,0,10);
    quickSort(b,0,10);
    printarray(b,11);
    // cout<<binarySearchFound(a,0,5,6)<<'\n';
    return 0;
}