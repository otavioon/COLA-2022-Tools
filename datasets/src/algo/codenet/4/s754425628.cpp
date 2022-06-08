#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int> vec(K);
  for (int i = 0; i < K; i++) {
    cin >> vec.at(i);
  }
  
  for (int x = N; x < 100000; x++) {
    int tmp = x;
    set<int> s;
    
    while(tmp!=0) {
      s.insert(tmp%10);
      tmp /= 10;
    }
    
    bool flag = true;
    
    for (int i = 0; i < K; i++) {
      if(s.count(vec.at(i))) {
        flag = false;
      }
    }
    
    if(flag) {
      cout << x << endl;
      break;
    }
  }

}