#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define f first
#define s second
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	set<int>s;
	for(int i=0;i<10;i++)
		s.insert(i);

	for(int i =0;i<k; i++)
	{
		int j;
		cin>>j;
		s.erase(j);
	}

	for(int i = n; ; i++)
	{
		int j = i;
		while(j)
		{
			int h = j%10;
			if(s.find(h)==s.end())
				break;
			j/=10;
		}
		if(!j)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}