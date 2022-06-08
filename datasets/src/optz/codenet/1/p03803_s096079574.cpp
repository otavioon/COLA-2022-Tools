#include<iostream>
using namespace std;
#include<vector>

int main(){
  vector<int> x;
  x = {13,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int a, b;
  cin >> a >> b;
  if (x[a] > x[b]){
     cout << "Alice" << endl;
  }
  else if(x[a]==x[b]){
     cout << "Draw" << endl;
  }
  else {
    cout << "Bob" << endl;
  }
}
  