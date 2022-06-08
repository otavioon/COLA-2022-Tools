#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int  K;
  string N;
  cin >> N >> K;
  vector<int> D;
  int ar[10];
  memset(ar, 0, sizeof(ar));
  for (int i = 0; i < K; i++){
    int A;
    cin >> A;
    ar[A]++;
  }
  for (int i = 0; i <= 9; i++){
    if (!ar[i])
      D.push_back(i);
  }
  sort(D.begin(), D.end());
  int F = (N[0]-'0');
  bool ok = false;
  string S;
  for (int i = 0; i < D.size(); i++)
    if (F == D[i]){
      ok = true;
      S += (F+'0');
    }
  if (ok){
    for (int i = 1; i < N.size(); i++){
      F = N[i]-'0';
      for (int j = 0; j < D.size(); j++){
        if (F == D[j]){
          ok = true;
          S += F+'0';    
        }
      }
      if (!ok){
        for (int j = 0; j < D.size(); j++){
          if (D[j] > F){
            S += D[j] + '0';
            break;    
          }    
        }
      }
      ok = false;
    }
  }
  else {
    for (int j = 0; j < D.size(); j++){
      if (D[j] > F){
        S += (D[j] + '0');
        break;    
      }    
    }   
    for (int j = 1; j < N.size(); j++){
      S += '0';
    }
  }
  cout << S << endl;
  return 0;
}