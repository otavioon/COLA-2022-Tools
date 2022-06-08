#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[3][3];
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			cin>>a[i][j];
	int cnt=0;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			cnt+=a[i][j];
	if(cnt%3==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}