#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int d;
  bool c[10];
  for ( int i = 0; i < 10; i++)c[i] = true;
  for ( int i = 0; i < k; i++){
    cin >> d;
    c[d] = false;
  }
  int crr = n;
  while (1){
    ostringstream oss;
    oss << crr;
    string s = oss.str();
    bool flag = true;
    for ( int i = 0; i < s.size(); i++){
      int num = s[i] - '0';
      if ( !c[num]){
        flag = false;
        break;
      }
    }
    if ( flag ){
      break;
    } else {
      crr++;
    }
  }

  cout << crr << endl;


  return 0;
}