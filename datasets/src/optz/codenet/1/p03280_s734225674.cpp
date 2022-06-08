#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
int input(){
  int x;
  cin>>x;
  return x;
}
int abs(int x){
  if(x>=0){
    return x;
  }else{
    return -x;
  }
}
int gcd(int x, int y){
	if(x<y){
    return gcd(y,x);
  }
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}



int main() {
  int A=input();
  int B=input();
  cout<<(A-1)*(B-1)<<endl;
  
  

  



  
  
  

  


}
