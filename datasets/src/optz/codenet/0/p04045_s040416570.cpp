#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> D(K);
  
  for(int i = 0; i < K; i++){
    cin >> D.at(i);
  }
  
  bool A = true;
  
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < K; j++){
      if(i == D.at(j)){
        A = false;
        break;
      }
    }
    if(A == true && i >= N){
      cout << i << endl;
      return 0;
    }
    A = true;
  }
  
  A = true;
  
  for(int i = 10; i < 100; i++){
    for(int j = 0; j < K; j++){
      if(i / 10 == D.at(j) || i - i / 10 * 10 == D.at(j)){
        A = false;
        break;
        }
    }
    if(A == true && i >= N){
      cout << i << endl;
      return 0;
    }
    A = true;
  }
  
  A = true;
  
  for(int i = 100; i < 1000; i++){
    for(int j = 0; j < K; j++){
      if(i / 100 == D.at(j) || ((i - i / 100 * 100) / 10 == D.at(j)
         || i - i / 10 * 10 == D.at(j))){
        A = false;
        break;
      }
    }
    if(A == true && i >= N){
      cout << i << endl;
      return 0;
    }
    A = true;
  }
  
  A = true;
  
  for(int i = 1000; i < 10000; i++){
    for(int j = 0; j < K; j++){
      if(i / 1000 == D.at(j) || ((i - i / 1000 * 1000) / 100 == D.at(j)
         || ((i - i / 100 * 100) / 10 == D.at(j) || i - i / 10 * 10 == D.at(j)))){
        A = false;
        break;
      }
    }
    if(A == true && i >= N){
      cout << i << endl;
      return 0;
    }
    A = true;
  }
  
}