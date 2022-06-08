#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL<<60;
typedef pair<ll, ll> P;

int main() {
    cin>>N>>K;
    set<int> no;
    rep(i,K){
        cin>>A;
        no.insert(A);
    }
    reps(i, N, 1e+6 + 1){
        int temp = i;
        while(temp > 0){
            if(no.find(temp%10) != no.end()) break;
            temp /= 10;
        }
        if(temp == 0){
            cout<<i<<endl;
            return 0;
        }
    }
}