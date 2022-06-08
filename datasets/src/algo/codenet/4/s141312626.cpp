#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  set<int> dislike;
  for(int i = 0; i < k; i++){
    int tmp;
    cin >> tmp;
    dislike.insert(tmp);
  }
  //sort(like.begin(),like.end());
  for(int i = n; i < 10000; i++){
    vector<int> num;
    int ni = i;
    while(ni>0){
      num.push_back(ni%10);
      ni /= 10;
    }
    int flag = 0;
    for( auto k : num){
      if(dislike.count(k)){
        flag = 1;
        break;
      }
    }
    if(flag)continue;
    else{
      cout << i << endl;
      break;
    }
  }
  return 0;
}