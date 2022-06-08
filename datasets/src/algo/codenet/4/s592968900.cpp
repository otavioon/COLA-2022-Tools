#include<iostream>
#include<set>
#include<string>
using namespace std ;

set<int> s ;

bool ok(int n){
  string str = to_string(n) ;
  for(int i=0;i<str.size();i++){
    if(s.count(str.at(i)-'0')){
      return false ;
    }
  }
  return true ;
}

int main(){
  int n,k ;
  cin >> n >> k ;
  for(int i=0;i<k;i++){
    int x ; cin >> x ;
    s.insert(x) ;
  }
  while(1){
    if(ok(n)){
      cout << n << endl ;
      return 0 ;
    }
    n++ ;
  }
}