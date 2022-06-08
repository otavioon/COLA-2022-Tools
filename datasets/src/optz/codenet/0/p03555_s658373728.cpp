#include <bits/stdc++.h>
using namespace std;

int main() {
    string N,M,O,P,Q,R;
  cin >> N >> M >> O >> R >> Q >> P;
  vector<string> vec1 = {O,M,N};
  vector<string> vec2 = {R,Q,P};
  if (vec1 == vec2) {
    cout << "YES" << endl;
  }else{
      cout << "NO" << endl;
  }

}