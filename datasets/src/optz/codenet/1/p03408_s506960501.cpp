#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <map>
 
using namespace std;
 
int main (void) {
  int N ,M;
  string s;
  map<string, int> blue;
  map<string, int> red;
  string key[N], key2[M];
  cin >> N;
  for (int i=0; i<=N-1; i++) {
     cin >> s;
     key[i]=s;
     blue[s] = int (blue[s]) +1;
     s= ' ';
  }
  cin >> M;
  for (int i=0; i<=M-1; i++) {
     cin >> s;
     key2[i]=s;
     red[s] = int (red[s]) +1;
     s =' ';
  }
  int ans =0;
  int NM =max(N,M);
  for (int i=0; i<=NM-1; i++) {
    ans=max(ans, blue[key[i]]-red[key[i]] );
  }
  cout << ans;
}