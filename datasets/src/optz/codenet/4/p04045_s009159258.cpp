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
  vector<int>bn(10,-1);
  rep(i,10){
    rep2(j,i,10){
      if(b.at(j)){
        bn.at(i)=j;
      }
    }
  }
  int number = n;
  string s = to_string(number);
  char st=s.at(0);
  int stc=ctoi(s.at(0));
  bool ex=false;
  
  if(bn.at(stc)>0){
    cout<<bn.at(stc);
    ex=true;
  }
  if(ex){
    rep2(i,1,s.size()){
      st=s.at(i);
      stc=ctoi(s.at(i));
      cout<<bn.at(stc);
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


