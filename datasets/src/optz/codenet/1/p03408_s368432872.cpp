#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;  
  vector<string> blue;
  vector<int> blueM;

  cin >> n;
  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    if ( i == 0 ) {
      blue = {s};        
      blueM = {1};
    } else {
      int x = blue.size();
      for (int j=0; j<x; j++) {
        if( s == blue.at(j) ) {
          blueM.at(j) += 1;
          break;
        } else if ( j == x - 1 ){
          blue.push_back(s);
          blueM.push_back(1);
        }
      }      
    }  
  }

  int m;  
  vector<string> red;
  vector<int> redM;

  cin >> m;
  for (int i=0; i<m; i++) {
    string s;
    cin >> s;
    if ( i == 0 ) {
      red = {s};        
      redM = {1};
    } else {
      int x = red.size();
      for (int j=0; j<x; j++) {
        if( s == red.at(j) ) {
          redM.at(j) += 1;
          break;
        } else if ( j == x - 1 ){
          red.push_back(s);
          redM.push_back(1);
        }
      }      
    }  
  }
  
  int A = 0;
  for (int i=0; i<blue.size(); i++) {
  
    string s = blue.at(i);
    int a = blueM.at(i);

    for (int j=0; j<red.size(); j++) {
      if( s == red.at(j) ){
        a -= redM.at(j);
        break;
      }
    }
    if ( A < a) A = a;
  }
  cout << A << endl;
}
 
