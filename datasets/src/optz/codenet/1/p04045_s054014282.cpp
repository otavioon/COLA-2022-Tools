#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {

  int n, k, d[10];
  bool flag[10], ok=true;
  memset(flag, 1, sizeof(flag));
  cin >> n >> k;
  for(int i=0; i<k; i++){
    cin >> d[i];
    flag[d[i]]=false;
  }
  for(int i=1; i<10000; i++){
    if(n<=i){
      int s=i;
      for(int j=0; j<5; j++){
        if(!flag[s%10]){
          ok=false;
        }
        if(9<s){
          s/=10;
        }
      }
      if(ok){
        cout << i << endl;
        return 0;
      }
      ok=true;
    }
  }

  return 0;
}