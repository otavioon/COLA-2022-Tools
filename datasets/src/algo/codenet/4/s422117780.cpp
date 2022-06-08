#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n;int k;
	cin>>n>>k;
	set<char> st;
	for(char i='0';i<='9';i++)
	{
		st.insert(i);
	}
	set<char> st2;
	for(int i=1;i<=k;i++)
	{
		char x;cin>>x;
		st2.insert(x);
		st.erase(x);
	}
	int f=0;
	for(int i=0;i<n.length();i++)
	{
		if(st2.find(n[i])!=st2.end()&&f==0)
		{
			auto it=st.lower_bound(n[i]);
			cout<<*it;
			f=1;
		}
		else if(f==1)
		{
			auto it=st.begin();
			cout<<*it;
		}
		else if(f==0)
		{
			cout<<n[i];
		}
	}
	

}