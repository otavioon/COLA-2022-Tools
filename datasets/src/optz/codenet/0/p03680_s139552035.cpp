#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n){
    cin >> a[i];
    a[i]--;
  }
  int ans=0;
  int cnt=0;
  int temp=0;
  while(temp!=1 && cnt<=n+3){
    temp=a[temp];
    cnt++;
  }
  if(temp==1)cout << cnt << endl;
  else cout << -1 << endl;
return 0;}