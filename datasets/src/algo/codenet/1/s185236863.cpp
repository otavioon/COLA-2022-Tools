#include<bits/stdc++.h>
using namespace std;
int a[5][5],s;
int main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j],s+=a[i][j];
	if(s%3==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}