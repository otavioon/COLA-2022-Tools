#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
 
using namespace std;
 
int abss(vector<int> v, int b){
  int sum = 0;
  for(int i = 0; i < v.size(); i++){
    sum += abs(v.at(i) - (b + i + 1));
  }
  return sum;
}
 
int main(){
  int max = 30;
  int min = -30;
  int mid;
  int n;
  int t;
  int a, b, c;
  
  vector<int> v;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t; v.push_back(t);
  }
  while(min <= max){
    mid = (min + max) / 2;
    a = abss(v, mid);
    b = abss(v, max);
    c = abss(v, min);
    if (a == b || a == c) {
      cout << a << endl;
      return 0;
    }
    else if(a > b) {
      min = mid + 1;
    }else if(a > c){
      max = mid - 1;
    }else{
      min += 1;
      max -= 1;
    }
  }
    
}
