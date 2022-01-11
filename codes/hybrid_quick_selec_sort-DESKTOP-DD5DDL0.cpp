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