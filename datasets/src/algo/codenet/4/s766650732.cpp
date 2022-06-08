#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll INF=(1LL<<60);
const ld pi=acosl((ld)-1);
const ll mod = 1000000007;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
#define endn "\n"
using vi=vector<ll>;

template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

  void add(int x, int y, T z) {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      for(int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};

ll to_int(string s){
	ll ret=0;
	rep(i,s.size()){
		ret*=10;
		ret+=s[i]-'0';
	}
	return ret;
}

void f(ll index,string x,set<ll>&ans,set<ll>&d){
	// cout<<x<<endl;
	ans.insert(to_int(x));
		
	if(index==6)return;
	rep(i,10){
		if(d.find(i)!=d.end())continue;
		x.push_back('0'+i);
		f(index+1,x,ans,d);
		x.pop_back();
	}
}

bool solve(){
	ll n,k;cin>>n>>k;
	set<ll>d;
	rep(i,k){
		ll _;cin>>_;
		d.insert(_);
	}
	set<ll>ans;
	f(0,"",ans,d);
	cout<<*ans.lower_bound(n)<<endl;
	return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed;
	cout<<setprecision(30);
	return solve();
}
