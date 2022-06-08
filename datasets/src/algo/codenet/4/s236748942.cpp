#include<iostream>
#include<cstdio>
#include<set>
#define read(x) scanf("%d",&x)
#define write(x) printf("%d",x)
using namespace std;
int k , n; 
set <int> s;
bool cnt(int x)
{
	while(x > 0)
	{
		bool q = s.count(x % 10);
		if(!q)	return false;
		x /= 10;
	}
	return true;
}
int main()
{
	read(n);read(k);
	for(int i = 0 ; i <= 9 ; i++)
		s.insert(i);
	for(int i = 1 ; i <= k ; i++)
	{
		int x;
		read(x);
		s.erase(x);
	}
	int i;
	for(i = n ; !cnt(i) ; i++);
	printf("%d\n",i);
}