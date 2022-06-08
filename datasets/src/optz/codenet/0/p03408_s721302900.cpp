#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n,m,ans=0;
	string s[200],t[200];
	cin>>n;
	for (int i=0;i<n;i++) cin>>s[i];
	cin>>m;
	for (int i=0;i<m;i++) cin>>t[i];
	for (int i=0;i<n;i++)
		if (s[i]!=""){
			int a=1,b=0;
			for (int j=i+1;j<n;j++) if (s[i]==s[j]) a++,s[j]="";
			for (int j=0;j<m;j++) if (s[i]==t[j]) b++,t[j]="";
			if (a>b) ans=max(ans,a-b);
		}
	cout<<ans<<endl;
	return 0;
}