#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

/*
テストケース全てに目を通す
テストケースが2個以下だったらなんかある
N最小のコーナーケースがないか調べる
制約をしっかりと確認する（1からNまでの順列、全て異なる値などの制約も含め）
操作の逆順を考える
Codeforcesではscanfを使う
 */

int main() {
    string s;
    cin >> s;
    ll n=s.length();
    ll k;
    cin >> k;
    ll ons=0;
    ll ser=1;
    ll fi=1;
    ll en=0;
    bool he=true;
    bool sam=false;
  	if(n==1){
      cout << (n*k+1)/2;
      return 0;
    }
    rep(i,n){
        if(i!=0){
            if(s[i]==s[i-1]){
                ser++;
                if(he)fi++;
            }
        else{
            he=false;
            ons+=ser/2;
            ser=1;
            }
        if(i==n-1){
            if(s[0]==s[n-1]){
                sam=true;
                ons+=(fi+ser)/2;
                en=ser;
                }
            else{
                ons+=ser/2;
                }
            }
        }
    }
    if(he)cout << n*k/2;
    else if(sam){
        cout << ons*k-(fi+en)/2+fi/2+en/2;
    }
    else cout << ons*k;
}

/*



 */





