#include <string>
#include <bits/stdc++.h>
#include <stdio.h>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main() {
 int n,m;
  cin >> n;
  string tmp;
  vector<int> sum(n);
  for(int i=0;i<n;i++){
    sum.at(i)=1;
  }
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin >> tmp;
    for(int j=0;j<n;j++){
      if(tmp==s.at(j)){
        sum.at(j)++;
      }
    }
    s.at(i)=tmp;
  }
  cin >> m;
  
  for(int i=0;i<m;i++){
    cin >> tmp;
    for(int j=0;j<n;j++){
      if(s.at(j)==tmp){
        sum.at(j)--;
      }
    }
  }
  sort(sum.begin(), sum.end());
  if(sum.at(n-1)>0){
    cout << sum.at(n-1) << endl;
  }
  else{
    cout << "0" << endl;
  }
}
