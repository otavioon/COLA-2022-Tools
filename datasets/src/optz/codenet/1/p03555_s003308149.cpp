#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < n;i++)
#define ll long long
#include <bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define ull unsigned long long 

int main(){
  vector<string>data(2);
  string s="Yes";
  for(int i=0;i<2;i++){
    cin>>data.at(i);
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      if(data.at(i).at(j)!=data.at(1-i).at(2-j))
        s="No";
    }
  }
  cout<<s;
}
        
  