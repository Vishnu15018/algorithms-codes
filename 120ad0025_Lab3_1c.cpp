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
   if(r-p+1>=100){
       int q=floor((p+r)/2);
       merge_sort(arr,p,q);
       merge_sort(arr,q+1,r);
       merge(arr,p,q,r);
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
     merge_sort(arr,0,x-1);
        cout<<"After sort: ";
    display(arr,x);
    cout<<endl;
    
    
}