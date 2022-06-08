#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int start = 1;
  int finish = 2;
  bool finished = false;
  int N;
  cin >> N;
  vector<int> button(N);
  vector<bool> pushed(N);//default is false
  
  for(int i = 0; i < N; i++){
    cin >> button.at(i);
  }
  
  int n = start - 1;
  int count = 0;
  while(pushed.at(n) == false){
    count++;
    if(button.at(n) == finish){
      finished = true;
      break;
    }
    pushed.at(n) = true;
    n = button.at(n) - 1;
  }
  if(finished)
    cout << count << endl;
  else cout << -1 << endl;
}