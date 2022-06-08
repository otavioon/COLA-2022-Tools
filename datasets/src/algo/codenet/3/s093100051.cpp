#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) {
    
   int n;
   cin>>n;
    int a[100000];
    int b[100000];
    int c[100000];

    int b_n[100000];
    int temp=0;
    int sum=0;
    int SUM=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    for(int i=0;i<n;i++){
        for(int j=temp;j<n;j++){
            if(b[i]<c[j]){
                temp=j;
                b_n[i]=n-j;
                sum+=n-j;
                break;
            }
        }
    }

    temp=0;
    for(int i=0;i<n;i++){
        for(int j=temp;j<n;j++){
            if(a[i]>=b[j]){
                sum-=b_n[j];
            }else{
                SUM+=sum;
                temp=j;
                break;
            }
        }
       // cout<<SUM<<" ";
    }
   /* for(int i=0;i<n;i++){
        cout<<b_n[i]<<" ";
    }*/
    cout<<SUM<<endl;

    
    return 0;
}