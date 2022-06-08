#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int INF = 1<<29;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

long long int i,j;

long long int de(long long int a){
	for(int k=1;k<=100;k++){
		a=a/10;
		if(a==0){
			return k;
			break;
		}
	}
}



int main(){
	long long int n;
	long long int ans=INF;
	cin>>n;
	//output
	if(n==1)ans=1;
	else ans=2018;
	cout<<ans<<endl;
	return 0;
}