#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> Li(n);
  for(int i=0; i<n; i++) cin >> Li[i];

  sort(Li.begin(), Li.end());

  long long ans = 0;
  for(int b=0; b<n; b++){
    for(int a=0; a<b; a++){
      int r = lower_bound(Li.begin(), Li.end(), Li[a]+Li[b]) - Li.begin();
      int l = b + 1;
      ans += r - l;
    }
  }

  cout << ans << endl;

  return 0;
}
