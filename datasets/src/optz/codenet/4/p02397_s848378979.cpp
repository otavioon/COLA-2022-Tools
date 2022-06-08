#include<iostream>
using namespace std;
int main()
{
	int x,y;
	while(cin>>x>>y&&(x!=0&&y!=0))
    {
		x=x+y;
		y=x-y;
		x=x-y;
		cout<<x<<" "<<y<<'\n';
	}
	return 0;
}
