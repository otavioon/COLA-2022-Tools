#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
string a,b;
int main(){
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a==b) printf("YES\n");
	else printf("NO\n");
	return 0;
}