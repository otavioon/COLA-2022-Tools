#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	int a1,a2,a3,b1,b2 ,b3;
	bool l=false,m=false,n=false,k=false;
	int c[9]={};
	bool ans=false;
	for(int i=0;i<9;i++)cin>>c[i];
	if(c[1]-c[0]==c[4]-c[3]&&c[1]-c[0]==c[7]-c[6])k=true;
	if(c[2]-c[0]==c[5]-c[3]&&c[2]-c[0]==c[8]-c[6])l=true;
	if(c[3]-c[0]==c[4]-c[1]&&c[3]-c[0]==c[5]-c[2])m=true;
	if(c[6]-c[0]==c[7]-c[1]&&c[6]-c[0]==c[8]-c[2])n=true;
	if(k&&l&&m&&n)cout<<"Yes";
	else cout<<"No";
	}