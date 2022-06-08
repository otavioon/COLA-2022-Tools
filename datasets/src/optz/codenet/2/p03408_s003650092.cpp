#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;
 
#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(int)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
int a[200000];
int b[200000];

int main() {
  int n,m;
  cin >> n;
  map<string, int> fi;
  map<string, int> se;
  string tm;
  rep(i,n){
    cin >> tm;
    fi[tm]++;
  }
  cin >>m;
  rep(i,m){
    cin >> tm;
    se[tm]++;
  }
  int ans = 0;
  for(auto e: fi){
    ans = max(ans, fi[e.first] - se[e.first]);
  }
  cout << ans << endl;
}
