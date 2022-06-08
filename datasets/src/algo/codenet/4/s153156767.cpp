#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define ALLTRUE(xs) all_of(ALL(xs),[](bool x){return x;})
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define ANYTRUE(xs) any_of(ALL(xs),[](bool x){return x;})
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;

struct edge { int to,cost; };

int main() {
  int N,K;cin>>N>>K;
  set<int> DS;
  REP(i,K) { int d;cin>>d;DS.insert(d); }

  while (true) {
    string tmp = to_string(N);
    bool checker = true;
    REP(i,tmp.size()) {
      if (DS.find(tmp[i]-'0')!=DS.end()) checker = false;
    }
    if (checker) {
      OUT(N);
      break;
    }
    N++;
  }

  return 0;
}