#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;

  cin >> N;
  vector<string> Blue(N);
  for(int i=0 ; i<N ; i++)
    cin >> Blue.at(i);

  cin >> M;
  vector<string> Red(M);
  for(int i=0 ; i<M ; i++)
    cin >> Red.at(i);
  
  int point = 0;

  for(int i=0 ; i<N ; i++){
    int p = 0;
    for(int j=0 ; j<N ; j++){
      if(Blue.at(i) == Blue.at(j))
        p++; 
    }
    for(int j=0 ; j<M ; j++){
      if(Blue.at(i) == Red.at(j))
        p--;
    }
    if(point < p)
      point = p;
  }

  cout << point << endl;
}
