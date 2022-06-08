#include <iostream>
using namespace std;

int main()
{
	double a[10];
	
	for (int i=1;i<=9;i++)   cin>>a[i];
	if((a[4]-a[1]==a[5]-a[2] && a[4]-a[1]==a[6]-a[3] )&& (a[7]-a[1]==a[8]-a[2] && a[7]-a[1]==a[9]-a[3]))
	   cout<<"Yes"<<endl;
	else
	   cout<<"No"<<endl;
	   
	   return 0;
}