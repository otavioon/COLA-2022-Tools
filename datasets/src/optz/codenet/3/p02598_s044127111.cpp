#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){	
	
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> L(n);
	for(int i=0;i<n;i++)cin >> L[i];
	sort(L.begin(),L.end(),greater<long long>());
	if(k==0){
		cout << L[0] << endl;
		return 0;
	}
	
	long long start=1;
	long long end=L[0];
	long long mid;
	while(end-start>1){
		mid=(start+end)/2;
		long long cnt=0;
		bool ok=true;
		for(int i=0;i<n;i++){
			if(L[i]>mid){
				cnt+=(L[i]-1)/mid;
			}else{
				break;
			}
		}
		if(cnt>k)ok=false;
		if(ok)end=mid;
		else start=mid;
	}
	cout << mid << endl;
	return 0;
}
