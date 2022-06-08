#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<string>
#include<set>
#include<string.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int n, k;
	cin >> n >> k;
	set<int>d;
	int x;
	rep(i, k){
		cin >> x;
		d.insert(x);
	}
	int tmp;
	int cnt = 0;
	for (int i = n; i < 100000; i++){
		tmp = i;
		while (tmp>0){
			if (d.count(tmp % 10) != 0){
				cnt = 1;
				break;
			}
			tmp /= 10;
		}
		if (cnt == 1){
			cnt = 0;
			continue;
		}
		cout << i << endl;
		return 0;
	}
	return 0;
}
