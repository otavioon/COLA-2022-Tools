#include <iostream>
using namespace std;

int main(){
  int n, i;
  int a[n];
  cin >> n;
  for(i = 0; i < n; i++) cin >> a[i];
  bool b[n];
  for(i = 0; i < n; i++) b[i] = true;
  int num = 0;
  int count = 0;
  while(1){
    if(b[count]){
      num++;
      b[count] = false;
      count = a[count] - 1;
    }else{
      num = -1;
      break;
    }
    if(a[count] == 2){
      num++;
      break;
    }
  }

  cout << num << endl;
  return 0;
}
