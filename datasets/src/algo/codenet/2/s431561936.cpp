#include<iostream>
#include<set>
using namespace std;
multiset<int> Set;
int res=0;
int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		Set.insert(a);
	}
	if(!Set.empty())
	{
		auto it=Set.end();
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
}