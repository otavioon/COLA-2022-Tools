#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n,d,human=1;
  cin >> n >> d;
  int x = 2*d+1;
  int y=1;
  while(n>x*y){
    human++;
    y++;
  }
  cout << human << endl;
}
