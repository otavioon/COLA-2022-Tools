#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
bool used[50];
typedef pair<int,int>P;
int n,k,a[11];
void dfs(int d){
}
int main(){
  cin>>n>>k;
  set<int>st;
  r(i,k)cin>>a[i],st.insert(a[i]);
  for(int i=n;;i++){
    int c=i,f=0;
    while(c){
      if(st.count(c%10))f++;
      c/=10;
    }
    if(!f){
      cout<<i<<endl;
      return 0;
    }
  }
}