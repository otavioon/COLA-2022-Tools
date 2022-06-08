#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
  return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin >> a[i];
  ll b=a[0]/2;
  for(int i=1;i<n;i++){
    b=lcm(b,a[i]/2);
    if(b>m){
      puts("0");
      return 0;
    }
  }
  for(int i=0;i<n;i++)if((b/(a[i]/2))%2==0){puts("0");return 0;}
  ll ans=0;
  for(ll i=b;i<=m;i+=2*b)ans++;
  cout << ans << endl;
  return 0;
}