#include <bits/stdc++.h>
using namespace std;

int main(){
int N,ima,now;
  cin >> N;
int a[N];
  for(int i = 0;i < N;i++){
  cin >> a[i];
  }

ima = 1;
int cnt = 0;  
  for(int i = 0;i < N;i++){
    if(ima == 2){
    cout << cnt << endl;
      break;
    }
    
  else if(a[ima - 1] == 0){
    cout << -1 << endl;
    break;
  }  
    else{
      now = ima;
      ima = a[ima - 1];
      a[now - 1] = 0;
      cnt++;
    }
  
  }
  
  return 0;
}