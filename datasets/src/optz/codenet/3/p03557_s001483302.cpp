#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);vector<int>B(N);vector<int>C(N);vector<long long>D(N);for(int i=0;i<N;i++)cin>>A[i];for(int i=0;i<N;i++)cin>>B[i];for(int i=0;i<N;i++)cin>>C[i];
  sort(B.begin(),B.end());sort(C.begin(),C.end());
  for(int i=N-1;i>=0;i--){
    D[i]=C.end()-upper_bound(C.begin(),C.end(),B[i]);
    if(i!=N-1)D[i]+=D[i+1];
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    ans+=D[B.end()-upper_bound(B.begin(),B.end(),A[i])];
  }
  cout<<ans<<endl;
}