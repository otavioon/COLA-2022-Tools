#include <iostream>
using namespace std;
int a,b;
int main() {
	cin>>a>>b;a+=11;b+=11;a%=13;b%=13;
	if(a==b)cout<<"Draw"<<endl;
	if(a<b)cout<<"Bob"<<endl;
	if(a>b)cout<<"Alice"<<endl;
	return 0;
}