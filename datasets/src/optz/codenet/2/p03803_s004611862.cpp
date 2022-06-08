#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
map<int,int>mp;
int main()
{
	mp[2]=1;
	mp[3]=2;
	mp[4]=3;
	mp[5]=4;
	mp[6]=5;
	mp[7]=6;
	mp[8]=7;
	mp[9]=8;
	mp[10]=9;
	mp[11]=10;
	mp[12]=11;
	mp[13]=12;
	mp[1]=13;
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==b)
	{
		printf("Draw\n");
		return 0;
	}
	if(mp[a]<mp[b])printf("Bob\n");else printf("Alice\n");
	return 0;
}