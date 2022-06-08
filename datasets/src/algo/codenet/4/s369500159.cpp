#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, k;
    cin >> n >> k;
    set<int> s;
    rep(i,k){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i = n; i < 10000; i++){
        int num = i;
        bool ok = true;
        while(num){
            int x = num % 10;
            if (s.find(x) != s.end()){
                ok = false;
                break;
            }
            num /= 10;
        }
        if (ok){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}