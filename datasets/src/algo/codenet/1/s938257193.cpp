#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
  int c1, c2, c3, d1, d2;
  cin >> c1 >> c2 >> c3;
  d1 = c2 -c1; d2 = c3 - c2;
  for(int i = 1; i < 3; i++){
    cin >> c1 >> c2 >> c3;
    if(d1 != (c2 - c1) || d2 != (c3 - c2)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
