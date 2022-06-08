#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,i,j,cou=0,flag;
  cin >> N;
  vector<string> a(N);
  for(i=0;i<N;i++){
    cin >> a[i];
  }
  cin >> M;
  vector<string> b(M);
  for(i=0;i<M;i++){
    cin >> b[i];
  }
  for(i=0;i<M;i++){
    flag=0;
    for(j=0;j<N;j++){
      if(b[i]==a[j]){
        a[j]="";
        flag=1;
        break;
      }
    }
    if(flag)cou++;
  }
  cout << N-cou << endl;
}