#include<bits/stdc++.h>
using namespace std;
int a[5][5],s,x;
int main(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++)
			cin>>a[i][j],s+=a[i][j];
		x+=a[i][i];	
	}
	if(x*3==s) cout<<"Yes"<<endl; 
	else cout<<"No"<<endl;
	return 0;
}