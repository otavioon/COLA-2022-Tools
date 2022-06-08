#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto& a : A){
    cin >> a;
    a--;
  }
  set<int> used;
  int ii = 0;
  int count = 0;
  while(true){
    if(ii==1){
      cout << count << endl;
      return 0;
    }
    if(used.find(ii)!=used.end()){
      cout << -1 << endl;
      return 0;
    }
    used.insert(ii);
    ii = A[ii];
    count++;
  }
}