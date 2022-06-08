#include <bits/stdc++.h>
using namespace std;

int main() {
    string N,M,O,P,Q,R;
  cin >> N >> M >> O;
  vector<string> vec1 = {N,M,O};
  vector<string> vec2 = {P,Q,R};
  if (vec1 == vec2) {
    cout << "YES" << endl;
  }else{
      cout << "NO" << endl;
  }

}