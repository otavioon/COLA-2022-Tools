#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  int result=0;
  int a,b;
  for(int i=0; i<N; i++){
    if(i<N-1){
      cin >> b;
    }
    if(i==0){
      result+=b;
      a=b;
    }else{
      result+=min(a,b);
      a=b;
    }
  }
  cout << result << endl;
}