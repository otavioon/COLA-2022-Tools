#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int k;
  cin >> k;
  set<int> st;
  for(int i=0;i<k;i++){
    int u;
    cin >> u;
    st.insert(u);
  }
  int ans=0;
  int add=1;
  while(n){
  	int p = n%10;
    n/=10;
    if(st.find(p) == st.end()){
      ans = ans + p*add; 
    }
    else{
      while(st.find(p) != st.end()){
        p++;
        p%=10;
      }
      ans = ans + p*add;
    }
    add *= 10;
  }
  cout<<ans;
return 0;
}