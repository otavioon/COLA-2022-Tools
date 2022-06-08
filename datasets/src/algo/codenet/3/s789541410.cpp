#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
typedef int64_t llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define ld PRId64
#define n_max 100000

int n;

void judge(llong B[],llong C[],llong D[]){
    int c=0;
    REP(i,n){
        while(c < n){
            if(C[c] < B[i]) c+=1;
            else break;
        }
        D[i]=c;
    }
}

llong judge2(llong A[],llong B[], llong D[]){
    llong ans=0;
    llong tmp=0;
    int b=0;
    REP(i,n){
        while(b < n){
            if(B[b] < A[i]){
                tmp+=D[b];
                b+=1;
            }
            else break;
        }
        ans+=tmp;
    }
    return ans;
}

int main(){
    cin >> n;
    llong A[n_max+5],B[n_max+5],C[n_max+5];
    REP(i,n) scanf("%ld",&C[i]);
    REP(i,n) scanf("%ld",&B[i]);
    REP(i,n) scanf("%ld",&A[i]);
    sort(&A[0],&A[n]);
    sort(&B[0],&B[n]);
    sort(&C[0],&C[n]);

    
    llong D[n_max+5];
    judge(B,C,D);
    cout << judge2(A,B,D) << endl;
    
}