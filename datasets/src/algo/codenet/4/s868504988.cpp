#include <bits/stdc++.h>
#include <set>
#include <string>
using namespace std;
int main()
{
 int i,j,l,k,n;
 string s;
 set<int> x;
 for(i=0;i<=9;i++)
 x.insert(i);
 cin >> s >> n;
 l=s.length();
 while(n--)
 {
  cin >> k;
  x.erase(k);
 }
 for(i=0;i<l;i++)
 {
  if(x.find(s[i]-'0')==x.end())
  {
   k=*x.upper_bound(s[i]-'0');
   //cout << k << " ";
   s[i]=(char)(k+'0');
   for(j=(i+1);j<l;j++)
   s[j]=(char)(*x.begin()+'0');
   break;
  }
 }
 cout << s;
 return 0;
}