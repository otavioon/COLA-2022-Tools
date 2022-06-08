#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

int main() {
  int N,M;
  string str;
  map<string,int> points;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> str;
    if(points[str]==0){
      points[str]=1;
    }else{
      points[str]++;
    }
  }
  
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> str;
    if(points[str]==0){
      points[str]= -1;
    }else{
      points[str]--;
    }
  }
  
  int ans=0;
  for (auto iter = points.begin(); iter != points.end(); iter++){
    ans = max(iter->second, ans);    
  }
  cout << ans << endl;  
}