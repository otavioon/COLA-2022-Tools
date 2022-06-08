#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
//const ull mod = 1e9 + 7;
const ll mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

// conversion number to bit
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
    bit += char('0'+(num>>i & 1));
  }
  return bit;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    multiset<ll> st;
    REP(i, N){
    	ll tmp;
    	cin >> tmp;
    	st.insert(tmp);
    }

    ll res = 0;
    while((int)st.size()>0){
    	auto itr = st.end();
    	itr--;
    	ll val = *itr;
    	st.erase(itr);

    	ll tmp = 1;
    	while(tmp<=val){
    		tmp *= 2;
    	}
    	auto tar = st.find(tmp-val);
    	if(tar != st.end()){
    		res++;
    		st.erase(tar);
    	}
    }
    cout << res << endl;
    return 0;
}