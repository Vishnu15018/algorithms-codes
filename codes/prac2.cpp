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
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
int main(){
    int arr[]={1,5,4,3,5,4,6,8};
    int x=sizeof(arr)/sizeof(arr[0]);
    //display(arr,x);
    insertion_sort(arr,2,x-1);
    //display(arr,x);
    int n1=std::numeric_limits<int>::max();
    cout<<n1<<endl;
    


}