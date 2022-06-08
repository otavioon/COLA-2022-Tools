#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string S; cin >> S;
  ll K;  cin >> K;
  ll m = S.size();
  
  bool same = true;
  for(ll i = 0; i < m-1; i++){ if( S[i] != S[i+1]){ same = false;} }
  if(same){ cout << (m*K)/2 << endl; return 0;}
 
  ll cnt1 = 0; ll cnt2 = 0;
  string SS = S+S;
  
  ll head = 0; ll tail = 0;
  while(head < m && tail < m){
    
    if( S[head] != S[tail]){
      if( head == tail){head++; tail++;}
      else{ head++;}continue;}
    
    while(head < m && tail < m && S[head] == S[tail]){ tail++;}
    cnt1 += (tail-head)/2;
    head = tail;
  }
  
  head = 0; tail = 0;
  
  while(head < 2*m && tail < 2*m){
    
    if( SS[head] != SS[tail]){
      if( head == tail){head++;tail++;}
      else{ head++;}continue;}
    
    while(head < 2*m && tail < 2*m && SS[head] == SS[tail]){ tail++;}
    cnt2 += (tail-head)/2;
    head = tail;
  }
    
  ll y = cnt2-2*cnt1;
  ll x = cnt1;
  
  cout << K*x+(K-1)*y << endl; return 0;}