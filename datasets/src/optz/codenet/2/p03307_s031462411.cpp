#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
 
using namespace std;

int ans(vector<int> v, int b){
  int sum = 0;
  for(int i = 0; i < v.size(); i++){
    sum += abs(v.at(i) - (b + i + 1));
  }
  return sum;
}

int main(){
  int mid;
  int n;
  int t, sum = 0;
  int val;
  
  vector<int> v;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t; v.push_back(t - (i + 1));
  }
  sort(v.begin(), v.end());
  /*
  for (int i = -1; i < 2; i++){
  
  }
  */
  val = v.at(v.size() / 2);
  cout << ans(v, val) << endl;
}
