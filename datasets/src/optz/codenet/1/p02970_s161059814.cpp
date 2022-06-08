#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,d; cin >> n >> d;
  for(int i=1;i<21;i++){
    if((2*d+1)*i>=n){
      cout << i << endl;
      break;
    }
  }
}