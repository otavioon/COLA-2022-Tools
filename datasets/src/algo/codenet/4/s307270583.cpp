#include<bits/stdc++.h>
using namespace std;
int main(){
int n,t;
  cin>>n>>t;
  set<int> st;
  while(t--){
    int g;cin>>g;
  st.insert(g);
  }
  for(int i=n;i>=n;i++){
     string k =to_string(i);
    int f=0;
     for(int i=0;i<k.length();i++){
      if(st.find(k[i]-'0')!=st.end()){
        f=1;
        break;
      }
     }
    if(f==0){
    cout<<k;
      break;
    }
  }
}
