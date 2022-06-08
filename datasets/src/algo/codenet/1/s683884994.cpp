#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  
  int sm = 0;
  rep(i, 9){
    int c;
    cin >> c;
    sm += c;
  }

  if (sm % 3 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

}
