#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int bsearch(int *array, int lb, int ub, int key)
{
  int mid;
  while(ub-lb>1){
    mid  = (lb+ub)/2;
    if(array[mid]<key){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  return ub;
}

int main()
{
  int N;
  int a[110000], b[110000], c[110000];
  ll res=0;
  cin >> N;
  rep(i,N) cin >> a[i+1];
  rep(i,N) cin >> b[i+1];
  rep(i,N) cin >> c[i];
  a[0] = b[0] = 0;
  a[N+1] = b[N+1] = INF;

  sort(a,a+N+1);
  sort(b,b+N+1);
  sort(c,c+N);

  ll ab[110000];
  FOR(j,1,N){
    int idxA = bsearch(a, 0, N+1, b[j]);
    ab[j] = (ll)(idxA-1);
    //cout << b[j] << ":" << idxA << "(" << a[idxA-1] << "," << a[idxA] << "]" \
<< "-->" << ab[j] << endl;                                                      
  }
  rep(i,N){
    int idxB = bsearch(b, 0, N+1, c[i]);
    //cout << c[i] << ":" << idxB << "(" << b[idxB-1] << "," << b[idxB] << "]" \
<< "-->" << ab[idxB-1] << endl;                                                 
    rep(j,idxB){
      res += (ll)ab[j];
    }
  }
  cout << res << endl;
  return 0;
}
