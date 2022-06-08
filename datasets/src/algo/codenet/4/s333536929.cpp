#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
int main()
{
	int n,k;
	char a;
	set<char>S;
	string s;
	stringstream ss;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a;
		S.insert(a);
	}
	for(int i=n;;i++)
	{
		ss<<i;ss>>s;ss.clear();
		bool flag=true;
		for(int j=0;j<s.length();j++)
		{
			if(S.find(s[j])!=S.end())
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<s<<endl;
			return 0;
		}
	}
}