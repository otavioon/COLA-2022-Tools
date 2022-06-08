#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define For(i, a, b) for(int i = (a); i < (b); i++)
#define Rep(i, n) For(i, 0, (n))
#define Rrep(i, n) for(int i = (n - 1); i >= 0; i--)
#define pb push_back

const int inf = 999999999;
const int mod = 1000000007;

int main(){
	int sum = 0;
	Rep(i, 3){
		Rep(j, 3){
			int t; cin >> t; sum += t;
		}
	}
	if(sum % 3 == 0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}