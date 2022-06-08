/* *****fireice**** */

#include<bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pb emplace_back
#define el '\n'
#define N 1000000007
#define re return
#define PI 3.14159265
#define take(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define out(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define all(a) (a).begin(),(a).end()
#define forup(i,n) for(int (i)=0;i<(n);(i)++)
#define ford(i,n) for(int (i)=(n)-1;i>=0;(i)--)
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
        // m is added to handle negative x
    ll res = ((ll)x%m + (ll)m) % m;

    return res;
}

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

ll poww(ll a,ll b)
{
  ll ans=1;
  for(int i=1;i<=b;i++)
  {
    ans*=a;
  }
  return ans;
}

inline ll max(ll a, ll b)
{
  if(a>b) re a;
  else re b;
}

inline ll min(ll a, ll b)
{
  if(a>b) re b;
  else re a;
}

ll ncr(int n,int r)
{
  ll ans=1;
  r=min(r,n-r);
  forup(i,r)
  {
    ans=(ans*(n-i)/(i+1))%N;
  }
  re ans;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  //fastscan(t);
  while(t--)
  {
    int n,m,k;
    fastscan(n);
    int b[n-1];
    forup(i,n-1)
    cin>>b[i];
    int ans=0;
    ans=b[n-2]+b[0];
    for(int i=n-2;i>=1;i--)
    {
      ans+=min(b[i],b[i-1]);
    }

    cout<<ans;

  }


  return 0;
}
