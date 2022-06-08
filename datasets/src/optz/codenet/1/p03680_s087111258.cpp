#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,tmp,count;
  count = 1;
  cin >> N;
  vector<int> a(N);
  for(int j=0;j<N;j++){
    cin >> a.at(j);
  }
  tmp = a.at(0);
  for(int i; i < N; i++){
    for(int k; k < N;k++){
      if(tmp == 2){
        cout << count << endl;
        return 0;
      }
      else if(tmp == k){
        count++;
        tmp = a.at(tmp);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}