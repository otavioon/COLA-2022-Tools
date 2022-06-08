#include <bits/stdc++.h>

#define mp       make_pair
#define mt	 make_tuple
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF=1<<29;
const double EPS=1e-9;
const int MOD = 100000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int N,K;
set<char> set_bad;
int main(){
  cin >> N >> K;
  for (int i = 0; i < K; i++){
    char c;
    cin >> c;
    set_bad.insert(c);
  }
  for (int i = N; ; i++){
    string tmp = to_string(i);
    bool ok = true;
    for (int j = 0; j < tmp.size(); j++){
      if (set_bad.count(tmp[j]) > 0){
	ok = false;
	break;
      }
    }
    if (ok){
      cout << i << endl;
      return 0;
    }
  }
}
