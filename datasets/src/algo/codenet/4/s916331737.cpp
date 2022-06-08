#include<bits/stdc++.h>
using namespace std;
int main()
{
  string n;
  int k;
  cin>>n>>k;
  int arr[k];
  set<int> s;
  for(int i=0;i<k;i++)
  {
    cin>>arr[i];
    s.insert(arr[i]);
  }
  for(int i=0;i<n.length();i++)
  {
    while(s.find(n[i]-48)!=s.end())
    {
      n[i]=n[i]+1;
      if(n[i]==58)
        n[i]=48;
    }
  }
  cout<<n;
  return 0;
}