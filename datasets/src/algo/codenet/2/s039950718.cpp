#include<iostream>
#include<set>
using namespace std;
multiset<int> Set;
int res,a,n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		Set.insert(a);
	}
	while(!Set.empty())
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
	cout<<res<<endl;
}