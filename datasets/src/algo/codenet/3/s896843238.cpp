#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100001]={}, b[100001]={}, c[100001]={}, a_b[100001]={}, b_c[100001]={};

int main(){
  int n; cin >> n;
  for(int i=0; i<n; i++){cin >> a[i];}
  for(int i=0; i<n; i++){cin >> b[i];}
  for(int i=0; i<n; i++){cin >> c[i];}

  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  for(int i=0; i<n; i++){
    int cnt=0;
    while(a[cnt] < b[i] && cnt != n) cnt++;
    a_b[i] = cnt;
  }
  
  ll ans = 0;
  int cnt=0, sum=0;
  
  for(int i=0; i<n; i++){
    while(b[cnt] < c[i] && cnt !=n) {sum += a_b[cnt]; cnt++;}
    ans += sum;
  }

  cout << ans << endl;
}