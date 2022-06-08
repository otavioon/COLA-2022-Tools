#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  long long K;
  cin >> K;
  int N_S = S.length();
  
  string test;
  for(int i=0; i<3; i++){
    test.append(S);
  }
  
  int N = test.length();
  int cnt_f=0;
  int cnt_m=0;
  int cnt_l=0;
  
  for(int j=0; j<N-1; j++){
    if(test[j] == test[j+1]){
      if(j+1 < N_S){
        cnt_f++;
      }else if(N_S <= j+1 && j+1 < N_S*2){
        cnt_m++;
      }else{
        cnt_l++;
      }
      test[j+1] = 'A';
    }
  }

  if(K==1){
    cout << cnt_f;
  }else{
    cout << cnt_f + cnt_m*(K-1);
  }
  return 0;
}
