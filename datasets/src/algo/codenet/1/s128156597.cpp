#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  int c = 0, x = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> x;
      c += x;
    }
  }

  if(c % 3 == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" <<endl;
  }

  return 0;
}