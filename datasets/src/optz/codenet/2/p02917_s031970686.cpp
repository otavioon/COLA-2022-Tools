#include<iostream>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],b[MAXN];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		cin>>b[i];
	}
	//a[1]=b[1];
	long long sum=b[1];
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]<=b[i+1])
		{
			sum+=b[i];
		 } else {
		 	sum+=b[i+1];
		 }
	}
	sum+=b[n-1];
	cout<<sum<<endl;
 } 