#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;      
  

int digitNumber(ll x){
  int number=0;
  while(x>0){
    x/=10;
    number++;
  }
  return number;
}



int main() {
  ll N;
  cin >> N;
   
  vector<pair<ll,ll>> factor;
  for(ll a=1LL; a*a<=N;a++){
    if(N%a==0){
      ll b=(N/a);
      
      pair<ll,ll> p;     
      p=make_pair(a,b);
      
      factor.push_back(p);
    }
  }
  
  int answer=digitNumber(N);
  
  for(auto p: factor){
    int tmp=max(digitNumber(p.first),digitNumber(p.second));

    if(answer>tmp){
      answer=tmp;
    }
  }
  cout << answer << endl;

}