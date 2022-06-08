#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data(n);
  for(int i = 0; i < n; i++){
    cin >> data.at(i);
  }
  
  auto result = find(data.begin(), data.end(), 2);
  if (result == data.end()) {
    cout << -1 << endl;
    return 0;
  } 
  int tmp = 1;
  int m = 1;
  int cnt = 0;
  while(true){
    tmp = data.at(m - 1);
    cnt++;
    if(tmp == 2){
      cout << cnt << endl;
      return 0;  
    }
    if(tmp == 1 || tmp == m){
      cout << -1 << endl;
      return 0;
    }
    m = tmp;
  }
}