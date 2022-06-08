#include <bits/stdc++.h>
using namespace std;	
const int N=100005;
typedef long long int lint;

string a;
int b;


lint f1(string a)
{
	string t=a;
	a=a+a; 
	lint ans=0;
	for (int i = 0; i < a.size(); ++i)
		if(a[i]==a[i+1] && a[i]!=0)
		{
			ans++;
			a[i+1]=0;
		}
	if(a[a.size()-1]!=0) ans++;
	ans = ans*((b-1)/2);
	if(b%2)
	{
		a=t;
		for (int i = 0; i < a.size(); ++i)
		if(a[i]==a[i+1] && a[i]!=0)
		{
			ans++;
			a[i]=0;
			a[i+1]=0;
		}

	}
	else
	{
		a=t+t;
		for (int i = 0; i < a.size(); ++i)
		if(a[i]==a[i+1] && a[i]!=0)
		{
			ans++;
			a[i]=0;
			a[i+1]=0;
		}

	}

	return ans;
}
lint f2(string a)
{
	string t=a;
	a=a+a; 
	lint ans=0;
	for (int i = 0; i < a.size(); ++i)
		if(a[i]==a[i+1] && a[i]!=0)
		{
			ans++;
			if(i==0)
				a[i]=0;
			else
				a[i+1]=0;
		}
	if(a[0]!=0) ans++;
	ans = ans*(b/2);
	if(b%2)
	{
		a=a[a.size()-1] + t;
		for (int i = 0; i < a.size(); ++i)
		if(a[i]==a[i+1] && a[i]!=0)
		{
			ans++;
			a[i]=0;
			a[i+1]=0;
		}

	}
	return ans;
}
int main(){
	cin >> a >> b;
	if(a[0]!=a[a.size()-1])
	{
		lint ans=0;
		for (int i = 0; i < a.size(); ++i)
			if(a[i]==a[i+1] && a[i]!=0)
			{
				ans++;
				a[i]=0;
				a[i+1]=0;
			}
		ans = ans*b;
		cout << ans;
	}
	else
	{
		cout << min(f1(a),f2(a));		
	}
}
