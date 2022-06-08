#include <bits/stdc++.h>

using namespace std;

int main() {
char s[200];
long long k;
cin>>s>>k;
int flag=0;
int l=strlen(s);
long long ans=0;
for (int a=0;a<l;a++)
{
	if (a==0)
	{
	   if (s[0]==s[l-1]&&s[0]==s[1])
	   {
	      ans++;
	      s[0]='1';
		}
		continue;
	}
	if (a==l-1)
	{
	   if (s[0]==s[l-1])
	   {
	   	if (s[l-1]!=s[l-2])
	   	   flag=1;
	      ans++;
	      s[l-1]='3';
	      continue;
		}
	}
   if (s[a]==s[a-1])
   {
	   s[a]='2';
		a++;
      ans++;
	}
}
ans*=k;
if (flag)
   ans--;
cout<<ans;
	return 0;
}