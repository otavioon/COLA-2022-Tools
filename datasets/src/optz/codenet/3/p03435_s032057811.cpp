#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//以上テンプレ
int main(){
    vvl vec(3,vl(3));
    rep(i,3){
        rep(j,3){
            cin>>vec.at(i).at(j);
        }
    }
    rep(i,2){
        if(vec.at(i).at(0)-vec.at(i).at(1)!=vec.at(i+1).at(0)-vec.at(i+1).at(1)){
            cN;
            return 0;
        }else if(vec.at(i).at(1)-vec.at(i).at(2)!=vec.at(i+1).at(1)-vec.at(i+1).at(2)){
            cN;
            return 0;
        }
    }
    cY;
    }
