#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
using namespace std;
using ll=long long;
#define mod  1000000007

int main(int argc, char const *argv[]) {

  int c[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> c[i][j];
    }
  }
  int line1 = c[0][0] + c[1][1] + c[2][2];
  int line2 = c[0][1] + c[1][2] + c[2][0];
  int line3 = c[0][2] + c[1][0] + c[2][1];
  if(line1 == line2 && line2 == line3) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}
