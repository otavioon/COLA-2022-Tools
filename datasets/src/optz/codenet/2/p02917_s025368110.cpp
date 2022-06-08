#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back
#define pb push_back

vector<int> a;
vector<int> x;

int main(void){
  int n;
  int ans = 0;
  int r = 0;

  cin >> n;
  a.resize(n);
  rep(i,n-1) cin >> a[i];
  r = a[0];
  rep(i,n-1){
    ans += min(r, a[i]);
    r = a[i];
  }
  ans += r;
  cout << ans << endl;

  return 0;
}
