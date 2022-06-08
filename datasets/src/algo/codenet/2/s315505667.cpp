#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
  int i,n,t;
  cin >> n;
  multiset<int, std::greater<int>>a;
  for(i=0;i<n;i++){
    int t;
    cin>>t;
    a.insert(t);
  }
  int ans=0;
  while(!a.empty()){
    int x=*a.begin();
    a.erase(a.begin());
    int y=pow(2,(int)log2(x)+1)-x;
    auto it=a.find(y);
    if(it!=a.end()){
      a.erase(it);
      ans+=1;
    }
  }
  cout << ans << endl;
}