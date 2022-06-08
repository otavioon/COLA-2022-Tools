#include <bits/stdc++.h>
using namespace std;
int main(){
	int val[15]={0,14},a,b;
	for(int i=2;i<=13;++i) val[i]=i;
	cin>>a>>b;
	cout<<(val[a]!=val[b]?val[a]>val[b]?"Alice":"Bob":"Draw");
}