#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int nanbanme(int n, vector<int> p){
  int a = 0;
  int b = p.size()-1;
  while(b-a > 1){
    if(n < p.at((a+b)/2)){
      b = (a+b)/2;
    }
    else{
      a = (a+b)/2;
    }
  }
  if(n<p.at(a)){
    return 0;
  }
  else if(n >= p.at(b)){
    return p.size();
  }
  else{
    return a+1;
  }
}

int main(){
  int n;
  cin >> n;
  set<int> A,B,C;
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    A.insert(m);
  }
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    B.insert(m);
  }
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    C.insert(m);
  }
  vector<int> a,b,c;
  for(auto i:A){
    a.push_back(i);
  }
  for(auto i:B){
    b.push_back(i);
  }
  for(auto i:C){
    c.push_back(i);
  }
  int na = a.size();
  int nb = b.size();
  int nc = c.size();
  long long count = 0;
  for(int i=0;i<na;i++){
    for(int j=nanbanme(a.at(i),b);j<nb;j++){
      count += (nc - nanbanme(b.at(j),c));
    }
  }
  cout << count << endl;
}