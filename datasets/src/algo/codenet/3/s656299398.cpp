#include<bits/stdc++.h>
#include<bitset>
#include<random>
#include<time.h>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

ll ba[N];
ll cb[N];

int main()
{
  int n;
  cin>>n;
  ll a[n], b[n], c[n];
  rep(i, 0, n)
    cin>>a[i];
  rep(i, 0, n)
    cin>>b[i];
  rep(i, 0, n)
    cin>>c[i];
  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);
  int j = 0;
  int co = 0;
  for(int i=0; i<n; i++)
  {
    while(j < n && a[j] < b[i])
    {
      co++;
      j++;
    }
    ba[i] = co;
  }
  ll ans = 0;
  j = 0;
  for(int i = 1; i<= n; i++)
  {
    while(j <n && b[j] < c[i-1])
    {
      ans += ba[j];
      j++;
    }
    cb[i] = cb[i-1] + ans;
  }
  cout<<cb[n]<<endl;
}
