#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> d(k);
	for(int i = 0; i < k; i++){
		cin >> d[i];
	}

	for(int x = n; x < 100000; x++){
		int tmp = x;
		set<int> s;
		while(tmp!=0){
			s.insert(tmp%10);
			tmp /= 10;
		}
		bool flag = true;
		
		for(int i = 0; i < k; i++){
			if(s.count(d[i])) flag = false;
		}
		if(flag){
			cout << x << endl;
			break;
		}
	}


	return 0;
}