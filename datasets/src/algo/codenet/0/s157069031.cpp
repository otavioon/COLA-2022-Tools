#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int64_t N=S.size();
  int64_t K;
  cin>>K;
  int64_t ans=0;

  if(S[0]==S[N-1]){
    int64_t a=0,b=N-1;
    int64_t cnt=0;
    while(a<N && S[a]==S[0]){
      ++a;
      ++cnt;
    }
    if(a==N) cout<<(K*N)/2<<endl;
    else{
      while(b>=0 && S[b]==S[N-1]){
        --b;
        ++cnt;
      }
    for(int i=a;i<b+1;++i){
      if(i<b){
        int64_t j=i+1;
        while(j<b+1 && S[j]==S[i]) ++j;
        ans += (j-i)/2;
        i=j-1;
      }
    }
    ans *= K;
    ans += a/2;
    ans += (N-b-1)/2;
    ans += (K-1)*((a+N-b-1)/2);
    cout<<ans<<endl;
  }
  }
  else{
    for(int i=0;i<N;++i){
      if(i<N-1){
        int j=i+1;
        int cnt=0;
        while(j<N && S[i]==S[j]){
          ++j;
        }
        ans += (j-i)/2;
        i=j-1;
      }
    }
    cout<<K*ans<<endl;
  }

}
