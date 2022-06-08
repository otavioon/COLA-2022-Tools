#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <typeinfo>

using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<bool> D(10,false);
  for(int i=0;i<K;i++){
    int d;
    cin >> d;
    D.at(d)=true;
  }

  for(int i=N;i<1000000;i++){
    int x=i;
    bool flag=true;
    while(x>0){
      int y=x%10;
      x/=10;
      if(D.at(y)==true) flag=false;
    }
    if(flag){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}
