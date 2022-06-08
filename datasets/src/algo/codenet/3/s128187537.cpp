#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    ll i,j;
    cin >> N;
    ll A[N],B[N],C[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    for(i=0;i<N;i++){
        cin >> B[i];
    }
    for(i=0;i<N;i++){
        cin >> C[i];
    }
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);
    ll T[N];
    j=0;
    for(i=0;i<N;i++){
        while(B[i]>=C[j]&&j<N){
            j++;
        }
        T[i]=N-j;
    }
    for(i=1;i<N;i++){
        T[N-i-1]+=T[N-i];
    }
    ll ans=0;
    j=0;
    for(i=0;i<N;i++){
        while(A[i]>=B[j]&&j<N){
            j++;
        }
        if(j!=N)ans+=T[j];
    }
    cout << ans;
    return 0;
}
