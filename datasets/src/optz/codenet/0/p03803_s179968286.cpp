#include<bits/stdc++.h>
using namespace std;
int main()
{int a,b;cin>>a>>b;
if(a>=1&&b>=1)
{if(a<=13&&b<=13)
{
if(a==1)
{cout<<"ALICE";}
if(a>b)
{cout<<"ALICE";}
if(b==1)
{cout<<"BOB";}
if(b>a)
{cout<<"BOB";}
if(a==b)
{cout<<"DRAW";}
}
}
return 0;
}