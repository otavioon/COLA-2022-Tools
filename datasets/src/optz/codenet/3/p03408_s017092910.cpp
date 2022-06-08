#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N;
  vector<string> S(N);
  for(int i=0;i<N;i++){
    cin>>S.at(i);
  }
  cin>>M;
  vector<string> T(M);
  for(int i=0;i<M;i++){
    cin>>T.at(i);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    int pt=0;
    for(int j=i;j<N;j++){
      if(S.at(i)==S.at(j)){
        pt++;
      }
         }
         for(int j=0;j<M;j++){
           if(S.at(i)==T.at(j)){
             pt--;
           }
         }
    ans=max(ans,pt);
  }
  cout<<ans<<endl;
}