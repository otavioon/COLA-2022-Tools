#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main() {
  int n,k;
  cin >> n>>k;
  vector<int>d(k);
  vector<bool>b(10,true);
  rep(i,k){
    cin>>d.at(i);
    b.at(d.at(i))=false;
  }
  int number = n;
  string s = to_string(number);
  char st=s.at(0);
  int stc=ctoi(s.at(0));
  bool ex=false;
  rep2(i,stc,10){
    if(b.at(i)){
      cout<<i;
      ex=true;
      break;
    }
  }
  if(ex){
    int co;
    rep(i,10){
      if(b.at(i)){
        co=i;
        break;
      }
    }
    int length=s.size()-1;
    while(length--){
      cout<<co;
    }
  }
  else{
    rep2(i,1,10){
      if(b.at(i)){
        cout<<i;
        break;
      }
    }
    int co;
    rep(i,10){
      if(b.at(i)){
        co=i;
        break;
      }
    }
    int length=s.size();
    while(length--){
      cout<<co;
    }
  }
  
}


