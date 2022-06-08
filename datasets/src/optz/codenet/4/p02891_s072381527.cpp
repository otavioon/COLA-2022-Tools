#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define print(x) cout << (x) << endl;
#define sz(x) int(x.size())
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}
 
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pair<long long, long long> > prime_factorize(long long n) { //素因数分解、pairのfirstに底、secondに底の何乗
   vector<pair<long long, long long> > res;
   for (long long p = 2; p * p <= n; ++p) {
       if (n % p != 0) continue;
       int num = 0;
       while (n % p == 0) { ++num; n /= p; }
       res.push_back(make_pair(p, num));
   }
   if (n != 1) res.push_back(make_pair(n, 1));
   return res;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    string s;
    ll k;
    cin >> s >> k;
    ll ans = 0;
    if(s.size() == 1){
      print(k / 2);
      return 0;
    }
    rep(i,s.size()-1){
      if(s[i] == s[i+1]){
        if((i+2) < s.size()){
          if(s[i+1] == s[i+2]){
            s[i+1] += 1;
            ans++;
          }else{
            if((s[i+1] + 1) == s[i+2]){
              s[i+1] += 1;
              s[i+1] += 1;
              ans++;
            }else{
              s[i+1] += 1;
              ans++;
            }
          }
        }else{
          if(s[i+1] == s[0]){
            s[i+1] += 1;
            ans++;
          }else{
            if((s[i+1] + 1) == s[0]){
              s[i+1] += 1;
              s[i+1] += 1;
              ans++;
            }else{
              s[i+1] += 1;
              ans++;
            }
          }
        }
      }
    }
    if(ans == 0 && (s[0] == s[s.size()-1])){
      print(k-1);
      return 0;
    }
    print(ans * k);
}
