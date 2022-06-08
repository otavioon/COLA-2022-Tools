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
    if(i==0 || i==N-2) B.push_back(b);
    if(N==2) B.push_back(b);
  }
  int ans=0, temp=B[N];
  for(int i=N-1; i>=0; i--){
    temp=min(temp, B[i]);
    ans+=temp;
  }
  cout << ans << endl;
}