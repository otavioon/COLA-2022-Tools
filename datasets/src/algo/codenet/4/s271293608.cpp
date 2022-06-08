#include<bits/stdc++.h>

using namespace std;

int main(){
  int N,K; cin >> N >> K;
  
  vector<int> vec; 
  for(int i = 0; i < K; i++){
    int d; cin >> d;  vec.push_back(d);}
  
  for(int i = N; i < 100000; i++){
    
    bool flag = true;
    
    int tmp = i;
    set<int> s;
    while( tmp > 0){
      s.insert( tmp% 10); tmp /= 10;}
    //　s中にあって、vecにもある数があればfalse
    for(int j = 0; j < K; j++){
      if(s.count( vec[j])){ flag = false;} }
    
    if( flag){ cout << i << endl; break;}
  }
  
  return 0;}
    
    