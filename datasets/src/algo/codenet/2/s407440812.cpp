#include<bits/stdc++.h>
using namespace std;
int n,res;
multiset<int> Set;
int main()
{
	int i,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		Set.insert(a);
	}
	while(!Set.empty())
	{
		auto it = Set.end();
		it--;
		int x=*it;
		Set.erase(it);
		for(int i=1;i<=x;i*=2)
		{
			if(Set.find(i-x)!=Set.end())
			{
				Set.erase(Set.find(i-x));
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}