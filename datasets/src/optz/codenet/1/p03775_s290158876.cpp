#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,ans=0;
	cin>>n;
	for(int i=floor(sqrt(n));i>=1;i--)
	{
		if(n%i==0) 
		{
			d=n%i;
			while(d!=0)
			{
				ans++;
				d=d/10; 
			}
			cout<<ans<<endl;
			break;
		}
	}
}