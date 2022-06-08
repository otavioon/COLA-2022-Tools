#include<bits/stdc++.h>
using namespace std;
int c[5][5],sum=0;
int main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			cin>>c[i][j];
            sum+=c[i][j];
    }
	if(c[1][1]+c[3][3]==c[1][3]+c[3][1]&&sum%3==0)
    	printf("Yes");
    else
    	printf("No");
    return 0;
}