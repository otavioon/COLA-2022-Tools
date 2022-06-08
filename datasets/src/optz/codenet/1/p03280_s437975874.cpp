#include <iostream>
using namespace std;
int main(){
  long long N,M,Q,L[200000],R[200000],p[100000],q[100000],out[100000];
  cin>>N>>M>>Q;
  for(long long i;i<M;i++)cin>>L[i]>>R[i];
  for(long long i;i<Q;i++)cin>>p[i]>>q[i];
  for(long long i;i<Q;i++){
    out[i]=0;
    for(long long j;j<M;j++){
      if(p[i]<=L[j]&&q[i]<=L[j]&&p[i]<=R[j]&&q[i]<=R[j])out[i]++;
    }
    cout<<out<<endl;
  }
}