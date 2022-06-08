#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,k;
  cin >> n>>k;
  vector<int>d(k);
  vector<bool>b(10,true);
  rep(i,k){
    cin>>d.at(i);
    b.at(d.at(i))=false;
  }

  bool ex=true;
  int c=n;
  while(ex){
    string e=to_string(c);
    bool ch=true;
    rep(i,e.size()){
      if(!b.at(e.at(i)-'0')){
        ch=false;
        break;
      }
    }
    if(ch){
      cout<<c<<endl;
      ex=false;
    }
    else{
      c++;
    }
  }
}