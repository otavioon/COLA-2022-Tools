#include<bits/stdc++.h>
using namespace std;

multiset < int > arr; int N , cnt;

int main(){
	cin >> N;
	for(int i = 1 , x ; i <= N ; ++i){cin >> x; arr.insert(x);}
	while(!arr.empty()){
		int t = *--arr.end(); arr.erase(arr.find(t)); int x = 1 << (int)(log2(t + 0.1) + 1);
		if(arr.find(x - t) != arr.end()){arr.erase(arr.find(x - t)); ++cnt;}
	}
	cout << cnt; return 0;
}