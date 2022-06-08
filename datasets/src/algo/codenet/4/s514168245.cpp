#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int k;
  cin >> n>>k;
  set<int> s;
  for(int i=0;i<k;i++){
    int d;
    cin >> d;
    s.insert(d);
  }
  int ans;
  bool ok=1;
  for(ans=n;ans<100000;ans++){
    int v=ans;
    ok=1;
    while(v>=1){
      if(s.count(v%10)){
        ok=0;
        break;
      }else{
        v/=10;
      }
    }
    if(ok){
      cout<<ans<<endl;
      return 0;
    }
  }
}
   

