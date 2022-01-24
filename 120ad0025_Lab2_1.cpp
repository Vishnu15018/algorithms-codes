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
void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
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
   if(p<r){
       int q=floor((p+r)/2);
       merge_sort(arr,p,q);
       merge_sort(arr,q+1,r);
       merge(arr,p,q,r);
   }
}
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        for(int j=i-1;j>=0;j--){
            if(temp<arr[j]){
                  arr[j+1]=arr[j];
                  arr[j]=temp;
            }
            
            
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
    
    int arr[100000];
    
     for(int i=0;i<100000;i++){
         arr[i]=rand();
    
     }
    int x=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"After insertion sorting: "<<std::endl;
    	clock_t t;
	t = clock();
   //insertion_sort(arr,x);
   merge_sort(arr,0,x-1);
       t=clock()-t;
    
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %f seconds to execute \n", time_taken);
        	clock_t t1;
	t1 = clock();
   //insertion_sort(arr,x);
   bubble_sort(arr,x);
       t1=clock()-t1;
    
	double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %f seconds to execute \n", time_taken1);
//    display(arr,x);
//        std::cout<<"After bubble  sorting: "<<std::endl;
//    bubble_sort(arr,x);
//    display(arr,x);
//           std::cout<<"After merge  sorting: "<<std::endl;
//    merge_sort(arr,0,x-1);
//    display(arr,x);

}
