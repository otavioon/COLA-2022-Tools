#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define str string
#define rep(x,y) for(int i=x;i<y;i++)
#define REP(x,y) for(int j=x;j<y;j++)
#define all(x) x.begin(),x.end()
#define int long long
signed  main(){
  int N,K;
  str S;
  vector<int>A(3);
  cin>>N;
  sort(all(A));
  if(N%2==1)cout<<2*N<<endl;
  else cout<<N<<endl;
}
