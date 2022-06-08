#include<iostream>
#include<string>

using namespace std;

int main()
{
int i,k,t=0,l=1,u=1,p;
  string s;
  cin>>s>>k;
  if(s[0]==s[s.length()-1])
     {
       while(s[l-1]==s[l])
         ++l;
        while(s[s.length()-u]==s[s.length()-u-1])
         ++u;
     }
  for(i=l-1;i<s.length()-u-1;)
  {
p=1;i++;
    while(s[i]==s[i+1])
          {i++;p++;}
          t+=p/2;
          }
  t*=k;
  t+=(((l+u)/2)*(k-1));
          t+(u/2 + l/2);
  cout<<t;
  return 0;
}