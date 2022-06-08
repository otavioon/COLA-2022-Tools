#include <bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  string a;
  bool oh=0;
  cin>>s>>a;
  sort(s.begin(),s.end());
  sort(a.begin(),a.end());
  if(s.size()!=a.size()){
        cout<<"NO"<<endl;
        return 0;
  }

  for(int i=0;i<s.size();i++)
  {
      oh=0;
      if(s[i]!=a[i]) oh=1;
  }
  if(oh==1) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}
