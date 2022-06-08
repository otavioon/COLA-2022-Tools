#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void Main()
{
  int n;
  cin >> n;
  vector<int> l(n);
  REP(i, n)
  cin >> l[i];
  
  sort(ALL(l));
  
  int count = 0;
  
  for(int i = 1; i < n - 1; i++){
    for(int j = 0; j < i; j++){
      for(int k = n; k > i; k--){
        if(l[i] < l[j] + l[k] && l[j] < l[k] + l[i] && l[k] < l[j] + l[i])
          count++;
      }
    }
  }
  
  printf("%d", count);
}

int main()
{
  std::cout << std::fixed << std::setprecision(15);
  Main();
}