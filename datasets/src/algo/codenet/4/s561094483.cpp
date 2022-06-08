#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,k;
  cin >> n >> k;
  set<int> s;
  rep(i,10)s.insert(i);
  rep(i,k){
    int u;
    cin >> u;
    s.erase(u);
  }
  while(true){
    int o=n;
    int h=0;
    while(o){
      int j=o%10;
      o/=10;
      if(s.count(j)){
        j++;
      }
      else{
        h=1;
        break;
      }
    }
    if(h==0){
      cout << n << endl;
      return 0;
    }
    n++;
  }
}
