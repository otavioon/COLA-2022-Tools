#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  vector<vector<char>> vec(2,vector<char> (3));
  
  if(vec[0][0]==vec[1][2]&&vec[0][1]==vec[1][1]&&vec[0][2]==vec[2][0]){
    cout<<"YES"<<endl;
    }
  else{
    cout<<"NO"<<endl;
  }
}