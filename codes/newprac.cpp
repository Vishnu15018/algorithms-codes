#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int *t;
    t = a;
    a = b;
    b = t;
}

void merge(int *a, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++){
        L[i] = a[p + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = a[q + j + 1];
    }
    i = 0;
    j = 0;
    k = p;
    while(i < n1 & j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i++];
        }
        else{
            a[k] = R[j++];
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void insrt_srt1(int *arr, int p, int r){
    int i, j, key;
    for(i = p + 1; i <= r; i++){
        j = i - 1;
        key = arr[i];
        while((j > p) & (arr[j] > key)){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge_srt(int *a, int p, int r){
    if(p<r){
        int q;
        q = p + (r - p)/ 2;
        merge_srt(a, p, q);
        merge_srt(a, q + 1, r);
        merge(a, p, q, r);
    }
}
void hybrid_merge_srt1(int *a, int p, int r){
    
        if(r - p > 200){
            
            int q = p + (r - p)/ 2;
            hybrid_merge_srt1(a, p, q);
            hybrid_merge_srt1(a, q + 1, r);
            merge(a, p, q, r);
        }
        else{
             insrt_srt1(a, p, r);
        }
   
}



int main(){
    int s, i;
    cout<<"Enter size of the array: ";
    cin>>s;
    int r[s];
    for(i = 0; i < s; i++){
        r[i] = rand()%100000;
    }
    cout<<"start"<<" ";
    merge_srt(r, 0,s - 1);
    for(i = 0; i < s; i++){
        cout<<r[i]<<" ";
    }
    cout<<"end";
    cout<<endl;
}