#include<bits/stdc++.h>

using namespace std;

bool num[10] = {true};
// true →　useable

int main(){
int N,K; cin >> N >> K;
  
 for(int i = 0; i < K; i++){
   int d; cin >>d; num[d] = false;}
  
  int pay = N;
  
  while(1){
    set<int> se; int k = pay;
    while( k > 0){
      se.insert(k%10); k /= 10;}
    bool flag = true;
    for(auto ne : se){
      if( !num[ne]){ flag = false;}}
    //使っちゃいけない文字が含まれる場合
    
    if( flag){ break; }
    pay++;
  }
  
  cout << pay << endl; return 0;}
    