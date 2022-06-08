#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1001001001;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
//printf("%.10f\n", N);
/*
ll memo[100000];
ll fibo(ll n){
    if(memo[n] != 0)return memo[n];
    if(n <= 1)return n;
    else return memo[n] = fibo(n - 1)+ fibo(n - 2);
}*/
int main() {
    ll num[3][3];
    rep(i,3)
    rep(j,3)cin >> num[i][j];
    bool ans = true;
    rep(i,2){//横列
        if(num[i][0] - num[i + 1][0] != num[i][1] - num[i + 1][1] ||
            num[i][2] - num[i + 1][2] != num[i][1] - num[i + 1][1])ans = false;
    }
    rep(i,2){
        if(num[0][i] - num[0][i + 1] != num[1][i] - num[1][i + 1] ||
            num[2][i] - num[2][i + 1] != num[1][i] - num[1][i + 1])ans = false;
    }
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;
}