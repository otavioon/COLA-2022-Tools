#include "bits/stdc++.h"
using namespace std;
const int maxn = 200100;
int a[maxn];
int main(){
  int n;
  scanf("%d", &n);
  for(int e = 0; e < n; e++) scanf("%d", a + e);
  sort(a, a + n);
  set<pair<int, int> > b;
  for(int e = 0; e < n; e++) b.insert({a[e], e});
  int ans = 0;
  for(int e = n - 1; e >= 0; e--){
    set<pair<int,int> >::iterator me = b.lower_bound({a[e], e});
    if(me != b.end() && me->first == a[e] && me->second == e){
      long long lg = 1;
      while(a[e] >= lg) lg *= 2;
      int diff = (int)(lg - a[e]);
      auto nme = b.lower_bound({diff, -1});
      if(nme != b.end() && nme->first == diff && nme->second != e){
        b.erase(b.lower_bound({a[e], e}));
        b.erase(b.lower_bound({diff, -1}));
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
