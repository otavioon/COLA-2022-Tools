#include<bits/stdc++.h>
#define rep(i, n) for(int i; i < n; i++)

using namespace std;
 //桁数を求める
int f(int N){
  int counter = 0;
  while(N>0){
    N = N - (N%10);
    N = N/10;
    counter++;
  }
  return counter;
}
  
 
int main(){
  int N;
  cin >> N;
  
 vector<int> F;
  double D = pow(N, 0.5);
  
  for(int i = 1; i <= D; i++){
    if(N%i==0){
      F.push_back( max(f(i), f(N/i)) );
     
    }
  }
  
  
  int ans = *min_element(F.begin(), F.end());
 
  cout << ans << endl;
}
      
  




