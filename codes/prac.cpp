#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
void merge_hy(int arr[],int p,int q, int r){   
    if(p-r>=200){
        int n1,n2;
        n1=q-p+1;
        n2=r-q;
        int l1[n1];
        int r1[n2];
        for(int i=0;i<n1;i++){
            l1[i]=arr[p+i];
        }
        for(int j=0;j<n2;j++){
            r1[j]=arr[q+1+j];
        }

        int i=0,j=0,k=p;
        while(i<n1 && j<n2){
            if(l1[i]<=r1[j]){
                arr[k]=l1[i];
                i=i+1;
            }
            else{
                arr[k]=r1[j];
                j=j+1;
            }
            k++;
        }
        while(i<n1){
            arr[k]=l1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=r1[j];
            j++;
            k++;
        }
    }
    else{
        insertion_sort(arr,p,r);
    }
}

void merge_sort_hy(int arr[],int p,int r){
    if(p<r){
        int q=int((p+r)/2);
        merge_sort_hy(arr,p,q);
        merge_sort_hy(arr,q+1,r);
        merge_hy(arr,p,q,r);
    }
}

int main(){
    int arr2[1000];
    srand(0);
    for(int i=0;i<1000;i++){
        arr2[i]=rand()%10000;
    }
    printf("Array is: ");
    print(arr2,1000);
    printf("Sorted array by hybrid_quick sort is: ");
    quick_sort_hy(arr2,0,1000);
    print(arr2,1000);  
    printf("\n");

    int arr1[1000];
    srand(0);
    for(int i=0;i<1000;i++){
        arr1[i]=rand()%10000;
    }
    printf("Array is: ");
    print(arr1,1000);
    printf("Sorted array by hybrid_merge sort is: ");
    merge_sort_hy(arr1,0,1000);
    print(arr1,1000);  

}
