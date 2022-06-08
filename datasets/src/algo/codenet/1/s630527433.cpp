#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int i,j,x,s,t;
	s=t=0;
	for (i=0;i<3;i++)
	  for (j=0;j<3;j++)
	  {
	  	cin>>x;
	  	if (i==j) t+=x;
	  	else s+=x;
	  }
	if (t*2==s) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}