#include <iostream>
#include <cmath>

using namespace std;

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
void display(int arr[],int n){
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, i, y;
    cout<<"Enter size of the array: ";
    cin>>n;
    int radix[n];
    int *a;
    for(i = 0; i <= n; i++){
        radix[i] = rand()%10000;
    }
    radix_sort(radix, n);
    display(radix,n);
    cout<<endl;
}