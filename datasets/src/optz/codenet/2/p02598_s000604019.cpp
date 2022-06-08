#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  int n,k;
  cin >> n >> k;
  auto compare = [](pair<ll,ll> l, pair<ll,ll>r){
    return l.first*r.second<l.second*r.first;
  };

  priority_queue<pair<ll, ll>, 
  vector<pair<ll,ll>>,
  decltype(compare)> q{compare};

  for(int i=0;i<n;i++){
    ll a;
    cin >> a;
    q.push(make_pair(a,1));
  }

  for(int i=0;i<k;i++){
    pair<ll,ll> p;
    p=q.top(); q.pop();
    p.second++;
    q.push(p);
  }

  pair<ll,ll> ans;
  ans=q.top();

  if((ans.first%ans.second)==0) cout << ans.first/ans.second << endl;
  else cout << ans.first/ans.second+1 << endl;

  return 0;
}
