#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s; cin >> s;
  ll N = s.size();
  ll K; cin >> K;
  ll ans = 0;
  
  if(N == 1){
    cout << K / 2 << endl;
    return 0;
  }
  
  char c = s[0];
  ll fcnt = 1;
  while((c == s[fcnt]) && (fcnt < N)){
    fcnt++;
  }
  
  if(fcnt == N){
    cout << (N * K) / 2 << endl;
    return 0;
  }
  
  c = s[N-1];
  ll scnt = N - 1;
  while(c == s[scnt]){
    scnt--;
  }
  
  if(s[0] == s[N-1]){
    ans += ((fcnt + (N - 1 - scnt)) / 2) * (K - 1);
    //cout << ans << ' ';
    ans += fcnt / 2 + (N - 1 - scnt) / 2;
  }else{
    ans += fcnt / 2;
    ans += ((N - 1 - scnt) / 2) * K;
  }
  
  c = s[fcnt];
  ll tmp = 1;
  fcnt++;
  for(; fcnt <= scnt; fcnt++){
    if(s[fcnt] == c){
      tmp++;
    }
    else{
      ans += (tmp/2) * K;
      tmp = 1;
    }
    c = s[fcnt];
  }
  
  ans += (tmp/2) * K;
  
  cout << ans << endl;
}