#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
#include <string>
#include <functional>
#include <map>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

using ii = pair < int , int >;
using ti = tuple < int ,int ,int >;
using lint = long long;
using ll = pair < lint , lint >;

int main(){
	//freopen("in.txt","r",stdin);
	int s[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&s[i][j]);
		}
	}
	int d[3][2];
	for(int i=1;i<3;i++){
		for(int j=0;j<3;j++){
			d[i][j] = s[i][j] - s[i-1][j];
		}
		if(d[i][0]==d[i][1] && d[i][1]==d[i][2]){

		}
		else{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}
