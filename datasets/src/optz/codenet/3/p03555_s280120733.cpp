#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A,B,C;
  A=B=C=vector<int>(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cin>>B[i];
  for(int i=0;i<N;i++)cin>>C[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  int ans=0;
  for(int i=0;i<N;i++){
    int a=lower_bound(A.begin(),A.end(),B[i])-A.begin();
    int c=N-(upper_bound(C.begin(),C.end(),B[i])-C.begin());
    ans+=a*c;
  }
  cout<<ans<<endl;
}