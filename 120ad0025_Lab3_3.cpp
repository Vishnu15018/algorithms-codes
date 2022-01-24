#include<iostream>
#include<limits>
#include<cmath>
#include <cstdlib>
#include<time.h>
#include<fstream>
#include <iomanip>
using namespace std;
void swap(int *p,int *q){
    int temp=*p;
     *p=*q;
    *q=temp;
}
int maxi(int arr[],int n){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    return m;
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
          q=partition_lastpi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
}
void quick_sort_middlepi(int arr[],int p,int r){
      if(p<r){
          int q;
          q=partition_middlepi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
}
void quick_sort_firstpi(int arr[],int p,int r){
      if(p<r){
          int q;
          q=partition_firstpi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
}
void quick_sort_randompi(int arr[],int p,int r){
      if(p<r){
          int q;
          q=partition_randompi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
      }
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
void selection_sort_hyb(int arr[], int p,int r){
     for(int i=p;i<=r;i++){
         for(int j=i;j<=r;j++){
             if(arr[j]<arr[i]){
                 swap(arr[i],arr[j]);
             }
         }
     }
}
void quick_sort_hyb(int arr[],int p,int r){
      if((r-p+1)>=100){
          int q;
          q=partition_lastpi(arr,p,r);
          quick_sort_hyb(arr,p,q-1);
          quick_sort_hyb(arr,q+1,r);
      }
      else{
          selection_sort_hyb(arr,p,r);
      }
}
void insertion_sort_hyb(int arr[],int p,int r){

    
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

void merge_sort_hyb(int arr[], int p, int r){
   if(r-p+1>=200){
       int q=floor((p+r)/2);
       merge_sort_hyb(arr,p,q);
       merge_sort_hyb(arr,q+1,r);
       merge(arr,p,q,r);
   }
   else{
       insertion_sort_hyb(arr,p,r);
   }
}
void quick_sort_heap_hyb(int arr[],int p,int r){
      if((r-p+1)>=100){
          int q;
          q=partition_lastpi(arr,p,r);
          quick_sort(arr,p,q-1);
          quick_sort(arr,q+1,r);
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
void merge_sort_heap_hyb(int arr[], int p, int r){
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
int* counting_sort(int *arr,int n){
    int k= maxi(arr,n);
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
void counting_radix(int *arr, int n, int d){
    int c[10];
    int b[n];
    int i;
    int *rs;
    for(i = 0; i < 10; i++){
        c[i] = 0;
    }
    for(i = 0; i < n; i++){
        int q1 = pow(10, d);
        int q2 = pow(10,(d - 1));
        int k = ((arr[i] % q1) / q2);
        c[k] = c[k]  + 1;
    }
    for(i = 1; i < 10; i++){
        c[i] = c[i] + c[i - 1];
    }
    for(i = n - 1; i >= 0; i--){
        int q1 = pow(10, d);
        int q2 = pow(10,(d - 1));
        int k = ((arr[i] % q1) / q2);
        b[c[k] - 1] = arr[i];
        c[k] = c[k] - 1;
    }
    for(i = 0; i < n; i++){
        arr[i] = b[i];
    }
}

void radix_sort(int *arr, int n){

    counting_radix(arr, n, 1);
    counting_radix(arr, n, 2);
    counting_radix(arr, n, 3);
    counting_radix(arr, n, 4);
}
void time_taken_sorting(int arr[],int x,float h){
    ofstream f1;
    f1.open("120ad0025_Lab3_3excel.csv",std::ios_base::app);
    int sum=0;
    clock_t t1;
	t1 = clock();
    bubble_sort(arr,x);
    t1=clock()-t1;
    sum=sum+t1;
	double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds
	//printf("bubble sort took %f seconds to execute \n", time_taken1);

    // for selection sort 	
	t1 = clock();
    selection_sort_hyb(arr,0,x-1);
    t1=clock()-t1;
	double time_taken2 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("selection sort took %f seconds to execute \n", time_taken1);
    // for insertion sort 
    	
    t1 = clock();
    insertion_sort(arr,x);
    t1=clock()-t1;
    
	double time_taken3 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("insertion sort took %f seconds to execute \n", time_taken1);

        // for merge sort 	
    t1 = clock();
    merge_sort(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken4 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("merge sort took %f seconds to execute \n", time_taken1);
            // for quick sort 	
    t1 = clock();
    quick_sort(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken5 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("quick sort took %f seconds to execute \n", time_taken1);
            // for heap sort 	
    t1 = clock();
    build_heap(arr,x-1);
    heap_sort(arr,x-1);
    t1=clock()-t1;
    
	double time_taken6 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("heap sort took %f seconds to execute \n", time_taken1);
                // for quick sort _pivot middle	
    t1 = clock();
    quick_sort_middlepi(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken7 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("quick sort _pivot middle took %f seconds to execute \n", time_taken1);
                // for quick sort _pivot first	
    t1 = clock();
    quick_sort_firstpi(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken8 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("quick sort _pivot first took %f seconds to execute \n", time_taken1);
                    // for quick sort _pivot random	
    t1 = clock();
    quick_sort_randompi(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken9 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("quick sort _pivot random took %f seconds to execute \n", time_taken1);
            // for hybrid quick selection sort 	
    t1 = clock();
    quick_sort_hyb(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken10 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("hybrid quick selection sort took %f seconds to execute \n", time_taken1);
                // for hybrid merge insertion sort 	
    t1 = clock();
    merge_sort_hyb(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken11 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("hybrid merge insertion sort took %f seconds to execute \n", time_taken1);
                    // for hybrid quick heap sort 	
    t1 = clock();
    quick_sort_heap_hyb(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken12 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("hybrid quick heap sort took %f seconds to execute \n", time_taken1);
                        // for hybrid merge heap sort 	
    t1 = clock();
    merge_sort_heap_hyb(arr,0,x-1);
    t1=clock()-t1;
    
	double time_taken13 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("hybrid merge heap sort took %f seconds to execute \n", time_taken1);
        // for Linear_counting sort 	
    t1 = clock();
    counting_sort(arr,x);
    t1=clock()-t1;
    
	double time_taken14 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("counting sort took %f seconds to execute \n", time_taken1);
            // for Linear_radix sort 	
    t1 = clock();
    radix_sort(arr,x);
    t1=clock()-t1;
    
	double time_taken15 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	//printf("radix  sort took %f seconds to execute \n", time_taken1);
    f1<<std::fixed<<h+1<<","<<time_taken1<<","<<time_taken2<<","<<time_taken3<<","<<time_taken4<<","<<time_taken5<<","<<time_taken6<<","<<time_taken7<<","<<time_taken8<<","<<time_taken9<<","<<time_taken10<<","<<time_taken11<<","<<time_taken12<<","<<time_taken13<<","<<time_taken14<<","<<time_taken15<<endl;
    f1.close();
}
int main(){
    ofstream f1;
    f1.open("120ad0025_Lab3_3excel.csv",std::ios_base::app);
    f1<<"array N.O,bubble,selction,insertion,Merge,Quick,Heap,Quick-Pivot_mid,Quick-pivot-fir,Quick-pivot-random,Quick-selection,Merge-Insertion,Quick-heap,Merge-heap,counting,radix"<<endl;
    f1.close();
    // cout<<"ENTER THE SIZE OF ARRAY : " ;
    // int n1;
    // cin>>n1;
    // cout<<endl;
    int arr1[100][1000];
    
     srand((unsigned)time(NULL));

    for(int i=0;i<100;i++){
        for(int j=0; j<1000;j++){
            arr1[i][j]=rand()%10000;
            
        }
        

        //cout<<"For "<<i+1<<"th array time taken by sorting algorithms: "<<endl;
        int x=sizeof(arr1[i])/sizeof(arr1[i][0]);
        time_taken_sorting(arr1[i],x,i);
        


      }
      cout<<"SEE THE Excel file for values of run time or 100 arrys with 1000 random elements"<<endl;
	return 0;
}

