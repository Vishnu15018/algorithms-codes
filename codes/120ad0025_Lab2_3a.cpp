#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void selection_sort(int arr[], int p,int r){
     for(int i=p;i<=r;i++){
         for(int j=i;j<=r;j++){
             if(arr[j]<arr[i]){
                 swap(arr[i],arr[j]);
             }
         }
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
          selection_sort(arr,p,r);
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
     quick_sort(arr,0,x-1);
        cout<<"After sort: ";
    display(arr,x);
    cout<<endl;
    
    
}