#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
 
typedef pair<ll,ll> pairs;
vector<pairs> p;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
#define MAX_N 1000100
bool x[MAX_N];
ll num[MAX_N];
ll fibl[MAX_N]={0};
 
ll fib(ll a){
    if (fibl[a]!=0)return fibl[a];
    if (a==0){
        return 0;
    }else if (a==1){
        return 1;
    }
    return fibl[a]=fib(a-1)+fib(a-2);
}
 
ll eratosthenes(ll n) {
    int p = 0;
    for (ll i=0; i<=n; ++i) x[i] = true;
    x[0] = x[1] = false;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            p++;
            for(int j=2*i; j<=n; j+=i) x[j] = false;
        }
        
        num[i] = p;
    }
    return p;
}
 
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}
 
ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

int main(){
    ll a,b;
    cin>>a>>b;
    
    if (a==1)a+=13;
    if (b==1)b+=13;
    
    if (a > b)cout << "Alice" << endl;
    else if (b > a)cout << "Bob" << endl;
    else cout << "Draw" << endl;
    
    return 0;
}


