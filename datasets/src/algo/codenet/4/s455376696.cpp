#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n,k;
    cin >> n >> k;
    set<int> s;
    rep(i,k){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i = n;i <= 1000000; i++){
        bool ok = 1;
        //cout << i << endl;
        int copy = i;
        while(copy > 0){
            if(s.count(copy%10)) ok = 0;
            copy /= 10;
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}