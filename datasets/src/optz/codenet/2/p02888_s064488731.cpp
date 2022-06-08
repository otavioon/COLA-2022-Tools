#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
long long n,a[1010],b,ans;
map<long long,int> m;
long long c[1010];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n); 
	/*for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
			c[a[i]]++;*/
	for(int i=0;i<n-2;i++)
	{
		for(int o=i+1;o<n-1;o++)		
		{
			if(i!=0 && a[i]==a[i-1])
				break;
			if(a[o]==a[o-1] && o-1!=i)
				continue;	
			long long l=o+1,r=n,w=0,r1=0;
			while(r-l!=1)
			{
				w=(l+r)/2;
				if(a[w]>=a[i]+a[o])
					r=w;
				else
					l=w;	
			}
		//	cout<<i<<" "<<o<<" "<<w<<endl;
			if(a[r]<a[i]+a[o] && r!=n)
				r1=r;
			else if(a[l]<a[i]+a[o])
				r1=l;
			else
				continue;
			for(int j=o+1;j<r1;j++)
				if(a[j]==a[j+1])
					ans--;			
			ans+=r1-o;	
		}
	} 
	cout<<ans<<endl;				
} 