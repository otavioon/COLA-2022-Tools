#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  vi c(9);
  rep(i, 9) cin >> c[i];
  bool ans = false;
  rep(i,c[0]+1){
    rep(j,c[4]+1){
      rep(k,c[8]+1){
        if(c[1]==i+c[4]-j&&c[2]==i+c[8]-k&&c[3]==j+c[0]-i&&c[5]==j+c[8]-k&&c[6]==k+c[0]-i&&c[7]==k+c[7]-j){
          ans = true;
        }
      }
    }
  }
  if(ans)print("Yes");
  else print("No");
}