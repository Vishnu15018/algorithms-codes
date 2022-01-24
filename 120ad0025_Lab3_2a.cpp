#include<iostream>
#include<limits>
#include<cmath>
#include <cstdlib>
#include<time.h>
using namespace std;
int max(int arr[],int n){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    return m;
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int* counting_sort(int *arr,int n,int k){

    int c[k+1];
    for(int i=0;i<=k;i++){
         c[i]=0;
    }
    for(int j=0;j<n;j++){
        c[arr[j]]=c[arr[j]]+1;
    }
        for(int i=1;i<=k;i++){
         c[i]=c[i]+c[i-1];
    }
    

    int *B=new int[n+1];
    for(int j=n-1;j>=0;j--){
        B[c[arr[j]]]=arr[j];
        c[arr[j]]=c[arr[j]]-1;
    }

    return B;

}

int main(){
    srand((unsigned)time(NULL));
    int arr[10000];
    
     for(int i=0;i<10000;i++){
         arr[i]=rand();
     }
    int x=sizeof(arr)/sizeof(arr[0]);
     std::cout<<"before sorting: "<<std::endl;
    display(arr,x);
    int *p = counting_sort(arr,x,max(arr,x));
    std::cout<<"After sorting: "<<std::endl;

        for(int i=1;i<=x;i++){
         cout<<p[i]<<" ";
    }
    cout<<endl;

}