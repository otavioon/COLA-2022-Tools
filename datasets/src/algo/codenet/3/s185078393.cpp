#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b, c, d, ans=0;
    cin >> n;
    long long A[100010], B[100010], C[100010];
    for(long long i=0; i<n; i++){
        cin >> A[i];
    }
    for(long long i=0; i<n; i++){
        cin >> B[i];
    }
    for(long long i=0; i<n; i++){
        cin >> C[i];
    }
    sort(A, A+n);
    sort(B, B+n);
    sort(C, C+n);
    
    for(long long j=0; j<n; j++){
        a=-1; b=n;
        while(b-a>1){
            long long mid=(a+b)/2;
            if(A[mid]>=B[j]){
                b=mid;
            }
            else{
                a=mid;
            }
        }//aが答え
        c=-1; d=n;
        while(d-c>1){
            long long mid=(c+d)/2;
            if(C[mid]>B[j]){
                d=mid;
            }
            else{
                c=mid;
            }
        }//n-d答え
        ans += (n-d)*(b-0);
       // cout << b<< " " << (n-d)<<"\n";
    }


    
    cout << ans  <<"\n";
    return 0;
}