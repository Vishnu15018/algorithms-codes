#include<iostream>
#include<cmath>
using namespace std;
void swap(int *p,int *q){
    int temp=*p;
     *p=*q;
    *q=temp;
}
void percolate_down(int arr[],int hole,int thesize){
     int temp=arr[hole];
     
     for(;2*hole+1<=thesize;){
         int max=2*hole+1;
         if(max<thesize && arr[max+1]>arr[max]){
             max=max+1;
         }
         if(arr[max]>temp){
             arr[hole] = arr[max];
            //  arr[hole]=temp;
         }
         else{
             break;
         }
         hole=max;
     }
     arr[hole]=temp;
     //arr[hole]=temp;
}

void build_heap(int arr[],int thesize){
    for(int i= floor(thesize/2);i>=0;i--){
        percolate_down(arr,i,thesize);
    }
}
void heap_sort(int arr[],int thesize){
    int x=thesize;
    for(int i=0;i<=x;i++){
        swap(arr[0],arr[thesize]);
        thesize--;
        percolate_down(arr,0,thesize);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[10000];
    
     for(int i=0;i<10000;i++){
         arr[i]=rand();
    
     }
    int x=sizeof(arr)/sizeof(arr[0]);
    int thesize =x-1;
    cout<<"BEFOE heapify :  ";
    display(arr,thesize+1);
    cout<<endl;
    build_heap(arr,thesize);
    cout<<"AFTER heapify : ";
    display(arr,thesize+1);

    cout<<endl;
    cout<<"After sorting : ";
    heap_sort(arr,thesize);
    display(arr,thesize+1);
    cout<<endl;
   
}