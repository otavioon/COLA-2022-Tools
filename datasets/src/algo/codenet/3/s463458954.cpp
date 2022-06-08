#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[100010], B[100010], C[100010];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
    }
    for(int i=0; i<n; i++){
        cin >> C[i];
    }
    sort(A, A+n);
    sort(B, B+n);
    sort(C, C+n);
    long long ans=0;
    
    for(int j=0; j<n; j++){
        int a=-1, b=n;
        while(b-a>1){
            int mid=(a+b)/2;
            if(B[j]>A[mid]){
                a=mid;
            }
            else{
                b=mid;
            }
        }//aが答え
        int c=-1, d=n;
        while(d-c>1){
            int mid=(c+d)/2;
            if(C[mid]>B[j]){
                d=mid;
            }
            else{
                c=mid;
            }
        }//n-d答え
        ans += (n-d)*(a+1);
    }
    cout << ans << "\n";
    return 0;
}