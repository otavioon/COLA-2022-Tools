#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  bool used[n];
  rep(i,n) used[i]=false;
  int ind=n-1;
  int pw=30;
  int ans=0;
  while(ind>=0){
    if(used[ind]){
      ind--;
      continue;
    }
    while(a[ind]/((int)pow(2,pw))==0){
      pw--;
    }
    int k=a[ind]-pow(2,pw);
    //    int e=upper_bound(a,a+n,pow(2,pw)-k) - a;
    int s=lower_bound(a,a+n,pow(2,pw)-k) - a;
    //    cout << s << endl;
    if(a[s]!=pow(2,pw)-k){
      ind--;
      continue;
    }
    for(int j=s;;j++){
      if(a[j]!=a[s]) break;
      if(!used[j] && j!=ind){
	ans++;
	used[ind]=true;
	used[j]=true;
	break;
      }     
    }
    ind--;
  }
  cout << ans << endl;
  return 0;
    

}
