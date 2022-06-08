#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; int64_t K; cin >> S >> K;
  
  int64_t sumF = 0, sumS = 0, sumT = 0;
  
  string tmpF = S, tmpS = S + S, tmpT = S + S + S;
  
  for (int i = 0; i < tmpF.size() - 1; i++) {
    
    if (tmpF.at(i) == tmpF.at(i + 1)) {
      sumF++;
      tmpF.at(i + 1) = '0';
    }
    
  }
  
  for (int i = 0; i < tmpS.size() - 1; i++) {
    
    if (tmpS.at(i) == tmpS.at(i + 1)) {
      sumS++;
      tmpS.at(i + 1) = '0';
    }
    
  }
  
  for (int i = 0; i < tmpT.size() - 1; i++) {
    
    if (tmpT.at(i) == tmpT.at(i + 1)) {
      sumT++;
      tmpT.at(i + 1) = '0';
    }
    
  }
  
  int64_t addS = sumS - sumF, addT = sumT - sumS;
  
  if (K == 1) { cout << sumF << endl; return 0; }
  
  if ((K - 1) % 2 == 0) cout << sumF + (addS + addT) * ((K - 1) / 2) << endl;
  
  else cout << sumF + (addS + addT) * ((K - 1) / 2) + addS << endl;
  
}