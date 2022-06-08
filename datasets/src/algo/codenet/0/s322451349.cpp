#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  long long K;
  cin >> K;
  int N_S = S.length();
  if(N_S == 1){
    if(K>1){
      cout << K/2;
      return 0;
    }
  }
  
  string test;
  for(int i=0; i<4; i++){
    test.append(S);
  }
  
  int N = test.length();
  int cnt_1=0;
  int cnt_2=0;
  int cnt_3=0;
  int cnt_4=0;
  
  for(int j=0; j<N-1; j++){
    if(test[j] == test[j+1]){
      if(j+1 < N_S){
        cnt_1++;
      }else if(N_S <= j+1 && j+1 < N_S*2){
        cnt_2++;
      }else if(N_S*2 <= j+1 && j+1 < N_S*3){
        cnt_3++;
      }else{
        cnt_4++;
      }
      test[j+1] = 'A';
    }
  }

  if(K==1){
    cout << cnt_1;
  }else if(K==2){
    cout << cnt_1 + cnt_2;
  }else if(cnt_2 == cnt_3){
    cout << cnt_1 + cnt_2*(K-1);
  }else if((K-1)%2==0){
    cout << cnt_1 + (cnt_2 + cnt_3)*(K/2);
  }else{
    cout << cnt_1 + (cnt_2 + cnt_3)*(K/2) + cnt_4;
  }
  
  return 0;
}
