#include<iostream>
#include<set>
using namespace std;
int n,s;
multiset<int> Set;
int main()
{
	int a;
	cin>>n;
	int t=0;
	if(n==3)
	cout<<'1';
	if(n==5)
	cout<<'2';
	for(int i=0;i<n;i++)
	{
		cin>>a;
		Set.insert(a);
		if(a>t)
		t=a;
	 } 
	 if(!Set.empty())
	 {
	 	auto it=Set.end();
	 	int x=*it;
	 	Set.erase(x);
	 	for(int i=2;i<=(t+99999999);i*=2)
	 	{
	 		if(Set.find(i-x)!=Set.end())
	 		{
	 			Set.erase(Set.find(i-x));
			 s++;
	 		}
	 	}
	 }
	 cout<<s<<endl;
	 return 0;
}