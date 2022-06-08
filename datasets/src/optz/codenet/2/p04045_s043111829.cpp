// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 042 Iroha's Obsession c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()

using ll = long long;

int main()
{
  string N;
  int K,n,tmp;
  cin >> N >> K;
  vector<int> L{1,2,3,4,5,6,7,8,9,0};
  REP(i,K) {
    int min = 0;
    int max = 9;
    cin >> n;
    while(min <= max) {
      tmp = (min+max)/2;
      if (L[tmp] == n) {
        L[tmp] = L.back();
        L.pop_back();
      } else if (L[tmp] < n) min = tmp+1;
      else max = tmp-1;
    }
  }
  REP(i,N.size()) {
    tmp = N[i] - '0';
    REP(j,L.size()) {
      if (L[j] >= tmp) {
        cout << L[j];
        break;
        if (i == N.size()-1 && j == L.size()-1) {
          cout << L[0] << (L[0]==0?L[1]:L[0]);
        }
      }
    }
  }
  cout << endl;
  
  return 0;
}
