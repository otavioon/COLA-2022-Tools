#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  
  vector<string> word;
  vector<int> cnt;
  
  int i,j;
  string tmp;
  
  cin >> tmp;
  word.push_back(tmp);
  cnt.push_back(1);
  bool exist;
  
  for(i=1;i<N;i++){
    cin >> tmp;
    exist = false;
    for(j=0;j<word.size();j++){
      if(tmp == word.at(j)){
        cnt.at(j) += 1;
        exist = true;
        break;
      }
    }
    if(exist != true){
      word.push_back(tmp);
      cnt.push_back(1);
    }
  }
  
  cin >> M;
  for(i=0;i<M;i++){
    cin >> tmp;
    //exist = false;
    for(j=0;j<word.size();j++){
      if(tmp == word.at(j)){
        cnt.at(j) -= 1;
        //exist = true;
        break;
      }
    }
    /*if(exist != true){
      word.push_back(tmp);
      cnt.push_back(1);
    }*/
  }
  
  int max;
  max = 0;
  for(i=0;i<cnt.size();i++){
    if(max < cnt.at(i)){
      max = cnt.at(i);
    }
  }
  cout << max;
       
        
}