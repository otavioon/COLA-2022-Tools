#include <bits/stdc++.h>
using namespace std;

int main() {
  int p[9];
  for (int i = 0; i < 9; ++i) {
    scanf("%d", &p[i]);
  }

  int a[3],b[3];
  a[0] = 0;
  a[1] = p[3] - p[0];
  a[2] = p[6] - p[0];
  b[0] = p[0];
  b[1] = p[1];
  b[2] = p[2];

  if(p[4]==a[1]+b[1] && p[5]==a[1]+b[2] && p[7]==a[2]+b[1] && p[8]==a[2]+b[2]){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}