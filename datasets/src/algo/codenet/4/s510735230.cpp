#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> D(K);
  for ( int i = 0; i < K; i++ ) {
    cin >> D[i];
  }
  
  for ( int i = N; i < 10000; i++ ) {
    int tmp = i;
    set<int> S;
    while( tmp != 0 ) {
      S.insert(tmp%10);     //各桁の値を格納→含まれている文字列が分かる
      tmp /= 10;
    }
    bool flag = true;
    
    for ( int j = 0; j < K; j++ ) {
      if( S.count(D[j]) ) flag = false;     //リストに格納されている変数を数える
    }
    
    if ( flag ) {
      cout << i << endl;
      break;
    }
    
  }
  
  return 0;
}