#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lli long long int
#define endl "\n"
int main()
{
string s;
lli k;
cin>>s>>k;
lli n=s.size();
if(n==1)
{cout<<k/2<<endl;return 0;}
char a=s[0];char b=s[n-1];lli x=-1;lli y=n;
for(lli i=0;i<n;i++)
{if(s[i]==a)
x=i;
else break;
}
for(lli i=n-1;i>=0;i--)
{
if(s[i]==a)
y=i;
else break;
}
lli z=x+n-y+1;
if(x>y)
{
lli ans=n*k;
ans/=2;
cout<<ans<<endl;return 0;
}
long long int ans=z;
z=z/2;
ans=(k-1)*z;x++;
z=n-y;
ans+=x/2;ans+=z/2;
//cout<<ans<<endl;
lli ans2=0;
//cout<<x<<" "<<y<<endl;
for(lli i=x;i<=y;i++)
{
if(s[i]==s[i-1])
{ans2++;i++;}
}
//cout<<ans2<<endl;
ans+=k*ans2;
cout<<ans;
}
