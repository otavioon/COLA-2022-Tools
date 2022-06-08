#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin >>N;
  int A[N],B[N-1];
  int ans=0;
  for(int i=0;i<N-1;++i) {
    cin >>B[i];
    if(i==0) ans+=B[i];
    if(i>=1) {
      if(B[i]<B[i-1]) ans+=B[i];
      if(B[i]>=B[i-1]) ans+=B[i-1];
    }
    if(i==N-2) ans+=B[i];
  }
  cout <<ans;
}
