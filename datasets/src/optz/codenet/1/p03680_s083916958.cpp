#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];

  for(int i = 0;i < n;++i){
    cin >> a[i];
  }
  int now = 0,c = 0;

  for(int i = 0;i < n;++i){
    if(now == 1){
      cout << c << endl;
      break;
    }
    if(c >= n){
      cout << -1 << endl;
      break;
    }
    ++c;
    now = a[now];
  }
}