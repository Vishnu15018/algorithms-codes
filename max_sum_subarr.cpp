#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
int  max_sum_arr(int arr[],int n){
    int over_max=arr[0];
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum>over_max){
                over_max=sum;
            }
        }
    }
    return over_max;

}
int cross_sum(int arr[],int p,int q,int r){
    int max1=0;
    int sum1=0;
    for(int i=q;i>=p;i--){
        sum1=sum1+arr[i];
        if(sum1>max1){
            max1=sum1;
        }
    }
        int max2=0;
    int sum2=0;
    for(int i=q+1;i<=r;i++){
        sum2=sum2+arr[i];
        if(sum2>max2){
            max2=sum2;
        }
    }
    return max1+max2;

}
int max3(int p,int q,int r){
    if(p>=q){
        if(p>=r){
            return p;
        }
        else{
            return r;
        }
    }
    else if(q>=r){
        return q;

    }
    else{
        return r;
    }

}

int max_sum_arr_2way(int arr[],int p,int r){
    if(p<=r){
        if(p==r){
            return arr[p];
        
        }
        int q=floor((p+r)/2);
        int m1=max_sum_arr_2way(arr,p,q);
        int m2=max_sum_arr_2way(arr,q+1,r);
        int m3=cross_sum(arr,p,q,r);
        return max3(m1,m2,m3);

    }
    else{
    return std::numeric_limits<int>::min();
        
    }
}

int cross_sum_new(int arr[],int p,int q1,int q2,int r){
    int sum1=0;
    for(int i=q1;i<=q2;i++){
        sum1=sum1+arr[i];
    }
    int max1=0;
    int suml=0;
    for(int i=q1-1;i>=p;i--){
        suml=suml+arr[i];
        if(suml>max1){
            max1=suml;
        }
    }
    int max2=0;
    int sumr=0;
    for(int i=q2+1;i<=r;i++){
        sumr=sumr+arr[i];
        if(sumr>max2){
            max2=sumr;
        }
    }
    return sum1+max1+max2;
}
int max(int p,int q){
    if(p>q){
        return p;
    }
    return q;
}
int max_sum_arr_3way(int arr[],int p,int r){
    if(p<=r){
        if(p==r){
            return arr[p];
        }        
        int q1=p+floor((r-p)/3);
        int q2=p+floor((2*(r-p))/3);
        cout<<"P= "<<p<<" q1= "<<q1<<" q2 = "<<q2<<" r= "<<r<<endl;
        int m1=max_sum_arr_3way(arr,p,q1);
        int m2=max_sum_arr_3way(arr,q1+1,q2);
        int m3=max_sum_arr_3way(arr,q2+1,r);
        int m4=cross_sum(arr,p,q1,q2);
        int m5=cross_sum(arr,q1+1,q2,r);
        int m6=cross_sum_new(arr,p,q1,q2,r);
        int ma1=max3(m1,m2,m3);
        int ma2=max3(m4,m5,m6);
        return max(ma1,ma2);
    }
    return std::numeric_limits<int>::min();
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int x=sizeof(arr)/sizeof(arr[0]);
    cout<<max_sum_arr_2way(arr,0,x-1)<<endl;
   cout<<max_sum_arr_3way(arr,0,x-1)<<endl;
   // cout<<max_sum_arr_2way(arr,0,x-1)<<endl;
    //cout<<std::numeric_limits<int>::min()<<endl;
}
