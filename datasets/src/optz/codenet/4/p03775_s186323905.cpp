#include <bits/stdc++.h>
using namespace std;
int Decimal(int N){
  int num=0;
  while(N==0){
    N=N/10;
    num++;
  }
  return num;
}

    
int main(){
  int N; //Nの数
  int A=1,B=1,C=0; //AとBの数の入れ物を用意
  int ans=12;
  /////入力部/////
  cin >> N;
  
  for (int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(i*j == N){
        A = Decimal(i);
        B = Decimal(j);
        C = max(A,B);
        if(C < ans)ans =C;
      }
    }
  }
  cout<<C<<endl;
}

        
  
  
  
