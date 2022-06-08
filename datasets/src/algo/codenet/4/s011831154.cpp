#include<bits/stdc++.h>
using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int32_t main(){
	boost;
	int n , k;

	int a[10] = {0};

	cin >> n >> k;

	int temp;
	set<int> s;
	for(int i = 0 ; i < k ; ++i){
		cin >> temp;
		s.insert(temp);
		a[temp]++;
	}

	int num = n;
	while(1){
		string hell = to_string(num);
		bool flag = true;
		for(int i = 0 ; i < hell.size() ; ++i){
			if( s.find(hell[i] - '0') != s.end() ){
				flag = false;
				break;
			}
		}
		if(num >= n && flag){
			cout << num;
			return 0;
		}
		num++;
	}
	return 0;
}