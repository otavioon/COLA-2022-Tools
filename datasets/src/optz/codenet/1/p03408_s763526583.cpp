#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i; i<n; i++){
    cin>>s.at(i);
  }
  int m;
  cin >> m;
  vector<string> t(m);
  for(int i; i<m; i++){
    cin>>t.at(i);
  }
  int flag,top=0;
  for(int i=0; i<n; i++){
    flag=0;
    for(int j=0;j<n; j++){
      if(s.at(i)==s.at(j))
        flag++;
    }
    for(int j=0; j<m; j++){
      if(s.at(i)==t.at(j))
        flag--;
    }
    if(flag>top)
      top=flag;
  }
  cout<<top<<endl;
  
}

