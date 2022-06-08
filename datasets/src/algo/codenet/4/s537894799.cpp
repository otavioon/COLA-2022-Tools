#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	string n;
  ll k;
  cin>>n;
  cin>>k;
  set <ll> arr;
  for(ll i=0;i<k;i++){
    ll x;
    cin>>x;
    arr.insert(x);
  }
  
  // checking for the case when the n is fine
  ll flag=1;
  for(ll i=0;i<n.size();i++){
    ll temp=n[i]-'0';
    if (arr.find(temp)!=arr.end()){
      flag=0;
      break;
    }
  }
  
  if (flag) {
    cout<<n<<"\n";
    return 0;
  }
  
  ll num=stoi(n);
  //cout<<"pika"<<"\n";
  while(num){
    ll ok=1;
    ll temp=num;
    while(temp!=0){
      ll digit=temp%10;
      temp=temp/10;
      //cout<<digit<<" "<<temp<<"\n";
      if (arr.find(digit)!=arr.end()){
        ok=0;
        break;
      }
    }
    if (ok){
      cout<<num<<"\n";
      return 0;
    }
    num++;
  }
  
	return 0;
}
