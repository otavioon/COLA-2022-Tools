#include<iostream>
#include<map>
#include<vector>
#include<string>
#include <algorithm>
#include<math.h>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  m = n;
  int i;
  i = n;

  vector<pair<int,int> > c;

  while(i > 0 ){
    if(n%i == 0){
      c.push_back(pair<int,int>(to_string(i).size(),to_string(n/i).size()));
      i =pow(10,(to_string(i).size()-1));
    }
      i--;
  }
  for(int i = 0 ; i < c.size();i++){
     m = min(m,max(c[i].first,c[i].second));
  }
  cout << m  << endl;
  return 0;
}
