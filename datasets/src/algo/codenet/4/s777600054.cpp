#include<iostream>
#include<set>
#include<cmath>
using namespace std;

int main()
{
  int N, K, input, temp, moto, min, keta, ans, fin, kakunin;
  bool flag = false;
  int toridashi(int N, int keta);
  set<int> S;
  
  cin >> N >> K;
  for(int i = 0; i < K; i++){
    cin >> input;
    S.insert(input);
  }
  int i;
  for(i = N; i < 10*N; i++){
    flag = false;
    for(int j = 0; j < log10(i) ; j++){
      temp = toridashi(i, j);
      if(S.count(temp)){
        flag = true;
        break;
      }
    }
    if(flag == false) break;
  }
  cout << i << endl;
  
  return 0;
}


int toridashi(int i, int keta)
{
  for(int j = 0; j < keta; j++) i /= 10;
  return i % 10;
}