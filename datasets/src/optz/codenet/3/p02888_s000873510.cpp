#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<int>count(1001);
  for(int i=0;i<N;i++){
    cin>>A[i];
    count[A[i]]++;
  }
  for(int i=1;i<1001;i++)count[i]+=count[i-1];
  sort(A.begin(),A.end());
  long long ans=0;
  for(int i=N-1;i>1;i--){
    for(int j=1;j<i;j++){
      if(A[j]*2>A[i])ans+=count[A[j]]-count[A[i]-A[j]]-1;
      if(A[i]==A[j])ans--;
    }
  }
  cout<<ans<<endl;
}