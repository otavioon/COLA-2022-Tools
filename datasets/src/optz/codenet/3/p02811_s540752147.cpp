#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector <int> a(N);
  vector <int> b(N);
  vector <int> c(N,0);
  int A,B=0;
  for (int i=0;i<N;i++){
    cin>>a[i];
  }
  for (int i=0;i<N;i++){
    cin>>b[i];
  }
  if(a==b){
    cout<<0<<endl;
    return 0;
  }
  for (int i=0;i<N;i++){
    c[i]=i+1;
  }
  int count=1;
  while(next_permutation(c.begin(),c.end()))
    {
          if(c==a){
            A=count;
          }
          if(c==b){
            B=count;
          }
          count++;
        }
  cout<<abs(B-A)<<endl;
    return 0;
}