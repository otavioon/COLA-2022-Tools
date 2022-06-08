#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  int K;
  cin >> N >> K;
  vector<bool> flag(10,true);
  int D;
  for(int i=0;i<K;i++){
    cin >> D;
    flag.at(D)=false;
  }
  bool carry=false;
  string ans="";
  int x,j,mi;
  for(int i=0;i<=9;i++){
    if(flag.at(i)){
      mi=i;
      break;
    }
  }
  for(int i=N.size()-1;i>=0;i--){
    x=N.at(i)-'0';
    if(carry){
      x++;
      if(x==10){
        x=0;
      }else{
        carry=false;
      }
    }
    if(flag.at(x)){
      ans.push_back(x+'0');
    }else{
      for(j=x+1;j<=9;j++){
        if(flag.at(j)){
          for(auto & c:ans){
            c=mi+'0';
          }
          ans.push_back(j+'0');
          break;
        }
      }
      if(j==10){
        carry=true;
        for(j=0;j<x;j++){
          if(flag.at(j)){
            for(auto & c:ans){
              c=mi+'0';
            }
            ans.push_back(j+'0');
            break;
          }
        }
      }
    }
  }
  if(carry){
    if(flag.at(1)){
      ans.push_back('1');
    }else{
      for(int i=2;i<=9;i++){
        if(flag.at(i)){
          for(auto & c:ans){
            c=mi+'0';
          }
          ans.push_back(i+'0');
          break;
        }
      }
    }
  }
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}
