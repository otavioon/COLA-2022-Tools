#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  for(int i=0;i<n;i++) cin >> l[i];
  sort(l.begin(),l.end());
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if((upper_bound(l.begin(),l.end(),abs(l[n-i-1]-l[n-j-1]))-l.begin())<n-j-1){
        ans+= n-(upper_bound(l.begin(),l.end(),abs(l[n-i-1]-l[n-j-1]))-l.begin())-j-1;
      }
    }
  }
  
  cout << ans << endl;
}