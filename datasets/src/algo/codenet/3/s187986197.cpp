#include <iostream>
#include <cmath>

using namespace std;

long n,a[100000],b[100000],bc[100000],c[100000],sum;

void sort (long v[], long n)
{
	long aux;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if(v[i]>v[j])
			{
				aux = v[j];
				v[j]=v[i];
				v[i]=aux;
			}
}

long search (long v[], long x, long min, long max)
{
	int mij=(min+max)/2;
	//cout<<"MIN MAX "<<min<<' '<<max<<endl;
	if(min==max)
		return min;
	if(v[0]>x)
		return -1;
	if(v[mij]<x&&v[mij+1]>x)
		return mij;
	else if (v[mij]<x)
		return search (v,x,mij+1,max);
	else return search (v,x,min,mij);
}

long search2 (long v[], long x)
{
	int ok=1;
	if(v[0]>x)
		{
			ok=0;
			return -1;
		}
	for(int i=0;i<n;i++)
		if(v[i]<x&&v[i+1]>x)
		{
			ok=0;
			return i;
		}
		else if(v[i]==x&&v[i-1]<x)
		{
			ok=0;
			return i-1;
		}
	if(ok)
		{
			return n-1;
		}

}

int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		cin>>c[i];

	sort (a,n);
	sort (b,n);
	sort (c,n);

	int v1=0,v2=0;
	
	for(int i=0;i<n;i++)
	{
		bc[i]=search2(a,b[i])+1;
	}
	for(int i=0;i<n;i++)
	{
		v2=search2(b,c[i]);
		for(int j=0;j<=v2;j++)
			sum=sum+bc[j];
	}
	cout<<sum;
	cin>>n;
	return 0;
}