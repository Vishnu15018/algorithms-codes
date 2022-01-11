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
void insertion_sort(int arr[],int p,int r){

    
    for(int i=p;i<=r;i++){
        int temp=arr[i];
        for(int j=i-1;j>=p;j--){
            if(temp<arr[j]){
                  arr[j+1]=arr[j];
                  arr[j]=temp;
            }
            
            
        }
    }
}
void merge(int arr[],int p ,int q, int r){
     int n1=q-p+1;
     int left[n1+1];
     int m1=0;
     for(int i=p; i<=q;i++){
         left[m1]=arr[i];
         m1++;
     }
     int n2=r-q;
     int right[n2+1];
     int m=0;
     for(int j=q+1;j<=r;j++){
         right[m]=arr[j];
         m++;
     }
     int i=0;
     int j=0;
    left[n1]=std::numeric_limits<int>::max();
    right[n2]=std::numeric_limits<int>::max();
     for(int k=p;k<=r;k++){
         if(left[i]<=right[j]){
             arr[k]=left[i];
             i++;
         }
         else{
             arr[k]=right[j];
             j++;
         }
     }

}
void merge_sort(int arr[], int p, int r){
   if(r-p+1>=200){
       int q=floor((p+r)/2);
       merge_sort(arr,p,q);
       merge_sort(arr,q+1,r);
       merge(arr,p,q,r);
   }
   else{
       insertion_sort(arr,p,r);
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
    cout<<"Before sorting : "<<endl;
    display(arr,x);
    merge_sort(arr,0,x-1);
    cout<<"after sorting : "<<endl;

    display(arr,x);
    
}