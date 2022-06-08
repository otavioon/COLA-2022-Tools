#include<bits/stdc++.h>
using namespace std;
int min(int,int);
int main()
{
	int n,i;
	cin>>n;
	int p=n-1;
	int a[p];
	for(i=0; i<p; i++)
	cin>>a[i];
	if(p==1)
	cout<<a[0]*2;
	if(p==2)
	cout<<a[0]*2+a[1];
	if(p>2)
	{
		int s=0; 
		s+=a[0]*2;
		for(i=1; i<p-1; i++)
		s+=min(a[i],a[i+1]);
		s+=a[p-1];
		cout<<s;
	}
	
}
int min(int a,int b)
{
	if(a>=b)
	return b;
	else return a;
	
}