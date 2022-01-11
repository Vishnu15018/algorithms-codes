#include<iostream>
#include <cmath>
using namespace std;
int max(int x1, int x2){
    if(x1>=x2){
        return x1;
    }
    return x2;
}
int divide_conquer(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    else{
    int left[n/2];
    for(int i=0;i<floor(n/2);i++){
        left[i]=arr[i];
    }
    int y=ceil(n/2);
    int right[y];
    int j=0;
    for(int k=floor(n/2);k<n;k++){
        right[j]=arr[k];
        j++;
    }
    int x1=sizeof(left)/sizeof(left[0]);
    int x2=sizeof(right)/sizeof(right[0]);
    // cout<<"left size:  "<<x1<<"  right size"<<x2<<endl;
    int m1;
    m1=divide_conquer(left,x1);
    int m2;
    m2=divide_conquer(right,x2);
    return max(m1,m2);
    }
}
int main(){
    int arr[]={1,2,45,2,3345,2222,121424,56564};
    int x= sizeof(arr)/sizeof(arr[0]);
    cout<<divide_conquer(arr,x)<<endl;
   //cout<<sizeof(arr)/sizeof(int)<<endl;
}