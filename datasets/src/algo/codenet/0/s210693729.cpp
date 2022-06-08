#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }


int main()
{
  ll k;
  ll count=0;
  string s;
  ll size;
  cin>> s;
  cin>>k;
  size=s.length();
  char a,b,c;
  string ds;
  ll count2=0;
  ll ans=0;
  REP(i,2)
  {
    REP(j,size)
    {
        ds[i*size+j]=s[j];
    }
  }
  REP(i,size-1)
  {
    if(s[i]==s[i+1])
    {
      count=count+1;
      s[i+1]=0;
    }
  }
  REP(i,2*size-1)
  {
    if(ds[i]==ds[i+1])
    {
      count2=count2+1;
      ds[i+1]=0;
    }
  }
  if(count*2==count2)
  {
    ans=count*k;
    cout<<ans<<endl;
  }
  if(count*2!=count2)
  {


    REP(i,k)
    {
      if(i%2==0)
      {
        ans=ans+count;
      }
      if(i%2==1)
      {
        ans=count2+ans-count;
      }
    }
  cout<<ans<<endl;
  }
}
