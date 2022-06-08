#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  set<int>out;
  rep(i,k){
    int a;cin>>a;
    out.insert(a);
  }
  repi(i,n,n*100){
    int ti=i;
    int f=1;
    while(ti>0){
      if(out.count(ti%10))
      {
        f=0;
        break;
      }
      ti/=10;
    }
    if(f){
      cout<<i<<endl;
      return 0;
    }
  }

  return 0;

}
