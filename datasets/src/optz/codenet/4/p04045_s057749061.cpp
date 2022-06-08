#include <bits/stdc++.h>
using namespace std;

vector<bool> d(10,false);

bool det(int n){
  while(n > 0){
    int num = n%10;
    if(d.at(num)){
      return false;
    }
    n /= 10;
  }
  return true;
}

int main() {
  int n,k;
  cin >> n >> k;
  
  for(int i = 0; i < k; i++){
    int num;
    cin >> num;
    d.at(num) = true;
  }

  while(1){
    if(det(n)){
      cout << n << endl;
      break;
    }else{
      n++;
    }
  }
}
