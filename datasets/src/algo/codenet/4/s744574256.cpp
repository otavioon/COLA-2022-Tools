#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;

int main(){
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