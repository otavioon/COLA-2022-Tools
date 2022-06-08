#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int gcd(ll N){
    ll ans=1;
    for(ll i=sqrt(N)+1; 0<i; i--){
        if(N%i==0){
            ans=i;
          	break;
        }
    }
    return ans;
}
int digsum(ll N){
    bool a=true;
    ll ans=0;
    while(a==true){
        if(0<N){
            ans++;
            N-=N%10;
            N/=10;
        }
        else{
            a=false;
        }
    }
    return ans;
}
int main() {
    ll N;
    cin>>N;
     ll A=gcd(N);
     ll B=N/A;
    cout<<max(digsum(A),digsum(B))<<endl;
    }
