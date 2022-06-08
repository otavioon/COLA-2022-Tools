#include<iostream>
#include<set>
#include<cmath>
using namespace std;

int main()
{
  int N, K, input, temp, moto, min, keta, ans, fin;
  bool flag = false;
  set<int> S;
  
  cin >> N >> K;
  for(int i = 0; i < K; i++){
    cin >> input;
    S.insert(input);
  }
  for(int i = 0; i < 10; i++){
    if(!(S.count(i))){
      min = i;
      break;
    }
  }
  
  ans = 0;
  fin = log10(N);
  for(int i = 0; i < fin+1; i++){
    keta = 0;
    temp = N;
    while(temp >= 10){
      temp/=10;
      keta++;
    }
    moto = temp;
    while(1){
      if(S.count(temp) && flag == false){
        temp++;
      }else{
        if(flag == true) temp = min;
        else if(moto != temp) flag = true;
        break;
      }
    }
    ans += temp*pow(10, keta);
    N = N - moto*pow(10,keta);
  }
  cout << ans << endl;
  
  return 0;
}