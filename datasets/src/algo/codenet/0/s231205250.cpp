#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll a=0;
  ll c=s.size();
  ll cnt=0;
  if(s[0]!=s[c-1]){
    for(int i=0;i<c-1;i++){
      if(s[i]==s[i+1]){
        cnt++;
        s[i+1]='1';
      }
    }
    cout << cnt*k << endl;
  }
  else{
    for(int i=0;i<c-1;i++){
      if(s[i]!=s[i+1]){
        a=1;
      }
    }
    if(a==0){
      cout << c*k/2 << endl;
    }
    else{
      int x,y;
      for(int i=0;i<c-1;i++){
        if(s[i]!=s[i+1]){
          x=i;
          break;
        }
      }
      x++;
      for(int i=c-1;i>0;i--){
        if(s[i]!=s[i-1]){
          y=c-i-1;
          break;
        }
      }
      y++;
      //cout << x << endl;
      //cout << c-y << endl;
      for(int i=x;i<c-y;i++){
        if(s[i]==s[i+1]){
          cnt++;
          s[i+1]='1';
        }
      }
      //cout << cnt << endl;
      cout << cnt*k+(x+y)/2*(k-1)+x/2+y/2 << endl;
    }
  }
}