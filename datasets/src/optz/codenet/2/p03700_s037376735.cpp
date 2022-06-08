#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

vector<LL> h;
LL N;
LL A,B;

bool calc(LL a){    // a回爆破するときにすべての魔物を消し去れるかの判定 1クエリO(N)
    LL sum = 0;
    rep(i,N){
        LL t = h[i] - B*a;
        LL b = A - B;
        if(t > 0){
            sum += (t + b - 1)/b;       // A-Bで割った数の切り上げ
        }
    }
    return sum <= a;
}

int main(){
    cin >> N;
    cin >> A >> B;
    h.resize(N);
    rep(i,N)cin >> h[i];

    // 二分探索
    LL lb = 0;
    LL ub = 1000000001;
    while(ub - lb > 1){     // calc　を用いた二分探索で O(NlogN)程度
        LL mid = (lb + ub)/2;
        if(calc(mid))ub = mid;
        else lb = mid;
    }

    cout << ub << endl;
}
