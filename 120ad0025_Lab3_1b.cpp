#include<iostream>
#include<limits>
#include<cmath>
#include <cstdlib>
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

int partition_lastpi(int arr[], int p ,int r){
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(arr[j]<=x){
         i++;
         swap(arr[i],arr[j]);
        }
    
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quick_sort(int arr[],int p,int r){
      if((r-p+1)>=100){
          int q;
          q=partition_lastpi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
      else{
          int arr1[r-p+1];
          int m=0;
          for(int i=p;i<=r;i++){
              arr1[m]=arr[i];
              m++;
          }
          int thesize=r-p;
          build_heap(arr1,thesize);
          heap_sort(arr1,thesize);
          m=0;
         for(int i=p;i<=r;i++){
              arr[i]=arr1[m];
              m++;
          }
      }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
   cout<<"ENTER THE SIZE OF ARRAY : " ;
    int n1;
    cin>>n1;
    cout<<endl;
    int arr[n1];
    int x=sizeof(arr)/sizeof(arr[0]);
     srand((unsigned)time(NULL));

    for(int i=0;i<x;i++){
         arr[i]=rand();
      }
    cout<<"Before sort: ";
    display(arr,x);
    cout<<endl;
            clock_t t;
    t=clock();
     quick_sort(arr,0,x-1);
    t=clock()-t;
    double tt=(double(t))/CLOCKS_PER_SEC;
    cout<<"Time taken bythe heapsort code is : "<<tt<<endl;
        cout<<"After sort: ";
    display(arr,x);
    cout<<endl;
    
    
}