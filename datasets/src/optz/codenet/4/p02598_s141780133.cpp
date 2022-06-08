#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<set>
//int mod(int a,int b,int d);

#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int n,k;
  cin >> n >> k;
  int in;
  set<pair<double,int>> a;
  rep(i,n){
    cin >> in;
    a.insert(make_pair((double)in,1));
  }
  auto it = a.end();
  it--;
  if(k==0){
    cout<<(*it).first<<" "<<(*it).second<<endl;
    return 0;
  }
  
  double a1;
  int si;
  while(k>0){
    a1 = (*it).first;
    si = (*it).second;
    //cout<<(*it).first<<" "<<(*it).second<<endl;
    a.erase(it);
    a1 /= 2.0;
    k -= si;
    si *= 2;
    a.insert(make_pair(a1,si));
    it = a.end();
    it--;
  }

  int a2;
  if(k==0) a2 = ceil((*it).first);
  else a2 = ceil(a1*2.0);
  cout<<a2<<endl;



}