#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>B(0,0);
  for(int i=0; i<N-1; i++){
    int b;
    cin >> b;
    B.push_back(b);
  }
  int ans=0, temp=B[N-2];
  for(int i=N-2; i>=0; i--){
    temp=min(temp, B[i]);
    ans+=temp;
//    cout<<"i:"<<i<<" temp:"<<temp<<" ans:"<<ans<<endl;
    if(i==0) ans+=temp;
  }
  cout << ans << endl;
}