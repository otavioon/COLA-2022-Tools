//ΔAGC029B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int f(int x){
	int i;
	for(i=2;i<=x;i=i+i);
	return i-x;
}
multiset<int> S;
multiset<int>::iterator it;
int main()
{
	int n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		S.insert(x);
	}
	n=0;
	while(!S.empty()){
		it=S.end();
		it--;
		x=*it;
		S.erase(it);
		x=f(x);
		it=S.lower_bound(x);
		if(it!=S.end()&&(*it)==x)
			S.erase(it),n++;
	}
	cout<<n;
	return 0;
}