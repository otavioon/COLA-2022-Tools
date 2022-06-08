#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  string s;int n;cin>>s>>n;
  ll cnt=0;
  int seq=0;
  if (s.size()==1){
    cout<<(n / 2)<<endl;
    return 0;
  }
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]){
      seq=2;
      while(1){
        i++;
        if(i==s.size())break;
        if(s[i]==s[i-1])seq++;
        break;
      }
      cnt += seq / 2;
      if(i==s.size()){
        if((seq % 2 == 1) && s[0] == s[s.size()]) {
          cnt++;
        }
      }
    }
  }
  cout<<cnt * n<<endl;

  return 0;
}
