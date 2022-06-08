#include<bits/stdc++.h>
using namespace std ;

int main () {
  vector<char> line(6) ;
  
  for ( int i = 0 ; i < 6 ; i++ ) {
    cin >> line.at(i) ;
  }
  
  if ( line.at(0) == line.at(5) && line.at(1) == line.at(4) && line.at(2) == line.at(3) ) {
    cout << "YES" << endl ;
  } else {
    cout << "NO" << endl ;
  }
}
