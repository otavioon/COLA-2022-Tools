#include <iostream>
#include <vector>
using namespace std;
int main(void){

  int n;
  long ans = 0;
  cin >> n;
  vector<long> B;
  
  for(int i = 0; i < n-1; i++){
    int b;
    cin >> b;
    B.push_back(b);
  }
  

  long res_a = B[n-2];
  long res_b = 0;
  
  for(int i = n-2; i >= 0; i--){
    
    if(res_a > B[i]){
      res_a = B[i];
      ans += res_a;
      res_b = res_a;
    }
    else{
      ans += res_a;
      res_a = B[i];
      res_b = B[i];
    }
    
    
  }
  
  cout << ans << endl;
  
  
  return 0;
}