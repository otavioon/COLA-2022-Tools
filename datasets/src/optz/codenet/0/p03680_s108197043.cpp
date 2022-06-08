#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a.at(i);
  }
  int ans;
  vector<int> light(N);
  light.at(0) = 1;
  for(int i=1; i<N; i++){
    if(find(light.begin(),light.end(),a.at(light.at(i-1)-1))
       !=light.end()){
      ans = -1;
      break;
    }
    light.at(i) = a.at(light.at(i-1)-1);
    if(light.at(i)==2){
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}