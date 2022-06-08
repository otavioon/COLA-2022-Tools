#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  set<int>S;
  for(int i=0;i<K;i++){
   int d; cin>>d;
    S.insert(d);
  }int ans;
  for(int i=N; ;i++){
  string s=to_string(i);
    int n=s.size();
    bool x=true;
    for(int j=0;j<n;j++){
      char a=s.at(j);
      int b=a-'0';
      if(S.count(b)){x=false; break;}
    
    }if(x){
      ans=i; break;
    }
  
  
  }cout<<ans<<endl;
    return 0;
}
