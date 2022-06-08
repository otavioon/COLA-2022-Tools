#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

int main(){
	int n,K;cin >> n >> K;
	vector<int> num;
	rep(i,10) num.push_back(i);
	rep(i,K) {
		int a;cin >> a;
		rep(j,num.size()){
			if(num[j]==a) num.erase(num.begin()+j);
		}
	}
	//rep(i,num.size()) cout << num[i]<< endl;
	int ans = 100000;
	for(int a:num)for(int b:num)for(int c:num)for(int d:num)for(int e:num){
		int temp = 10000*a+1000*b+100*c+10*d+e;
		int temp2 = 1000*b+100*c+10*d+e;
		int temp3 = 100*c+10*d+e;
		int temp4 = 10*d+e;
		int temp5 = e;
		if(temp >= n) ans = min(ans,temp);
		if(temp2 >= n) ans = min(ans,temp2);
		if(temp3 >= n) ans = min(ans,temp3);
		if(temp4 >= n) ans = min(ans,temp4);
		if(temp5 >= n) ans = min(ans,temp5);
	}
	cout << ans << endl;


	
}
 
 