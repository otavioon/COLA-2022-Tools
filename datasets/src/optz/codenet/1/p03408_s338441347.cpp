#include <bits/stdc++.h>
using namespace std;
 
int main() {
	vector<string> a;
    vector<int> b;
  int n,y;//yは同じ文字列が既に登場したか否か(1:yes 0:no)
  cin >> n;
  string s;
  for(int i;i < n;i++){
    cin >> s;
    for(int j = 0;j < a.size();j++){
      if(s == a.at(j)){
        b.at(j)++;
        y++;
        break;
      }
    }
    if(y == 0){
      a.push_back(s);
      b.push_back(1);
    }
    y = 0;
  }
  cin >> n;
  for(int i;i < n;i++){
    cin >> s;
    for(int j = 0;j < a.size();j++){
      if(s == a.at(j)){
        b.at(j)--;
        y++;
        break;
      }
    }
    if(y == 0){
      a.push_back(s);
      b.push_back(-1);
    }
    y = 0;
  }
  int m;
  for(int i;i < b.size();i++){
    if(b.at(i) > m) m = b.at(i);
  }
  cout << m << endl;
}