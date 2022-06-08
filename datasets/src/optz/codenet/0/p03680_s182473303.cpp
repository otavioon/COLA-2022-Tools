#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;cin >> n;
	vector <int> v(n);
	for(int i=0; i<n; i++){
	 cin >> v[i];
	 v[i]--;
	}
	int cnt=0;
	int index=distance(v.begin(), find(v.begin(), v.end(), 0));
	while(cnt<=n){
		if(v[index]==1){
			cout << cnt << endl;
			return 0;
		}
	   // cout << cnt << " index is " << index << endl;
		cnt++;
		index = v[index];
	}
	cout << -1 << endl;
	return 0;
}