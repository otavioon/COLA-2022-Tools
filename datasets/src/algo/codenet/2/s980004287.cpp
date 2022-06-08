#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define stpr setprecision
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REP(i,a,b) for(ll i=(a);i<(b);++i)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ld EPS=10e-8;
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
    for(auto i=begin(v); i != end(v); ++i){
        if(i !=begin(v)) os << ' ';
        os << *i;
    }
    return os;
}

ll A[2*MOD],C=0,T,Q,G;

void tsnnsaku(ll j){
    for(int i=30;i>0;i--){
        T=j;
        G=(pow(2,i));
        Q=G-T;
        if(Q>0){
            if( (Q!=j&&A[Q]>0) || A[Q]>1 ){
                A[Q]--;
                A[j]--;
                C++;
                return;
            }
        }
    }
}
 
int main() {
    ll N,B[200007];
    cin >> N;
    rep(i,N){
        cin >> B[i];
        A[B[i]]++;
    }
    sort(B,B+N);
    reverse(B,B+N);
    rep(j,N){
        if(A[B[j]]>0){
            tsnnsaku(B[j]);
        }
    }
    cout << C << endl;
}