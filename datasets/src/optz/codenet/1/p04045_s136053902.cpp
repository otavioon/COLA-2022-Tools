#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>

using namespace std;

int SolveCSub(int pay, int digit, const bool hate[10], int N){
  if(digit <= 0){
    if(pay >= N) return pay;
    else return 100000;
  }

  int iret = 100000;
  for(int i = 0; i < 10; i++){
    if(hate[i] && !(i == 0 && digit == 10000)) continue;
    int a = SolveCSub(pay + i * digit, digit/10, hate, N);
    if (a < iret) iret = a;
  }
  return iret;
}

void SolveC(){
  bool hate[10] = {false};
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < K; i++){
    int a;
    cin >> a;
    hate[a] = true;
  }

  cout << SolveCSub(0,100000,hate, N) << endl;
}

//int dp[100001];
int main(){
  SolveC();
/*
  const int kDiv = 1000000007;
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  dp[0] = 1;
  for(int y = 0; y < H-A; y++)
    for(int x = 0; x < W; x++)
      dp[x+1] = (dp[x+1] + dp[x]) % kDiv;

  for(int y = 0; y < A; y++)
    for(int x = B; x < W; x++)
      dp[x+1] = (dp[x+1] + dp[x]) % kDiv;
  cout << dp[W-1] << endl;
*/
  return 0;
}