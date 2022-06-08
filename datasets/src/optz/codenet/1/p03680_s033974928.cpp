#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a;
  cin >> N;
  
  vector<int> button;
  for(int i=1;i<=N;i++){
    cin >> a;
    button.push_back(a);
  }
  
  int ite=1,count=0;
  bool flg = false;
  for(int i=1;i<10000;i++){
    ite = button[ite-1];
    count++;
    if(ite==2){
      flg = true;
      break;
    }
  }
  if(flg){
    cout << count << endl;
  }else{
    cout << "-1" << endl;
  }
}
