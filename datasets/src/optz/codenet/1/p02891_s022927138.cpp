#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <map>
 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define for_p(i, a, b) for(int i = a; i < b; i++)
#define for_m(i, a, b) for(int i = a - 1; i >= b; i--)
 
//a = s1.size();
//vector<string> s1;
//string s2 = accumulate( s1.begin(), s1.end(), string() );
 
using namespace std;
 
int main()
{
  int a = 0 , b = 0, c = 0, d = 0, e = 0; //, f = 0;
  long f = 0;
  int i = 0, j = 0;
  int flug = 0;
  int flug2 = 0;
  double d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
  int a1[256], a2[512], a3[1024];
  //char s1[200000], s2[200000], s3[200000];
  string s1;
  cin >> s1 >> a;
  b = s1.size();
 
  for(i = 0; i < s1.size() - 1; i++){
    if(s1[i] != s1[i + 1]){
       flug++;
    }
  }
       
  if(flug != 0 && s1[b - 1] == s1[0]){
    for(i = 0; i < b - 1; i++){
      if(s1[i] == s1[i + 1]){
        flug2 = 1;
        while(flug2 == 1){
          f++;
          i++;
          if(!(s1[i] == s1[i + 1] && i < b - 1)){
            flug2 = 0;
          }
        }
      }
    }
    if(f == 0){
      f = a - 1;
    }else{
  	  f = f + a - 1 + (f - 1) * (a - 1);
    }
  }else if(flug != 0){
    for(i = 0; i < b - 1; i++){
      if(s1[i] == s1[i + 1]){
        flug2 = 1;
        while(flug2 == 1){
          f++;
          i++;
          if(!(s1[i] == s1[i + 1] && i < b - 1)){
            flug2 == 0;
          }
        }
      }
    }
    f *= a;
  }else{
    if(s1.size() == 1 && a == 1){
      f = 0;
    }else if(s1.size() == 1 && a % 2 != 0){
      f = a / 2;
    }else if(s1.size() * a % 2 == 0){
      f = s1.size() * a / 2;
    }else{
      f = s1.size() * a / 2 + 1;
    }
  }
	cout << f << endl;
}
  