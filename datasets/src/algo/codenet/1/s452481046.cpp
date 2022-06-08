#include <iostream>

int main(){
  int val, sum = 0;
  for(int i = 0; i < 9; ++i){
    std::cin >> val;
    sum += val;
  }
  
  std::string ans = "Yes";
  if(0 != sum % 3){
    ans = "No";
  }
  
  std::cout << ans << std::endl;
}