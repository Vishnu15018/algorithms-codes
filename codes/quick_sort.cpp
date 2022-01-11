#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
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
int partition_firstpi(int arr[], int p ,int r){
    swap(arr[p],arr[r]);
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
int partition_middlepi(int arr[], int p ,int r){
    int m=floor((p+r)/2);
    swap(arr[m],arr[r]);
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
int partition_randompi(int arr[], int p ,int r){
     srand(time(NULL)); 
    int m= p + (rand() % (r-p+1));
    swap(arr[m],arr[r]);
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
      if(p<r){
          int q;
          q=partition_randompi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    srand((unsigned)time(NULL));
    int arr[100000];
    
     for(int i=0;i<100000;i++){
         arr[i]=rand();
     }
    int x=sizeof(arr)/sizeof(arr[0]);
     std::cout<<"before sorting: "<<std::endl;
    display(arr,x);
    quick_sort(arr,0,x-1);
    std::cout<<"After sorting: "<<std::endl;

    display(arr,x);
}