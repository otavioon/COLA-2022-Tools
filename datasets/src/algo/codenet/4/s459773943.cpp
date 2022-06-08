/*
ID: marik_k1
PROG:
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

//ifstream fin ("input.txt");
//ofstream fout ("output.txt");

#define forn(i,n) for(int i = 0; i < n; ++i)
#define mp make_pair
#define pb push_back
#define all(t) t.begin(),t.end()
#define gcd(x,y) __gcd(x,y)

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 300000;
const int INF = (int)1e7;
const double eps = 1e-6;
const long long MOD = 1e9 + 7;
const double PI = M_PI;

set<int> s;
int n,k;
int ans;

bool good(int a){
	while(a){
		int r = a % 10;
		if(s.find(r) != s.end()){
			return false;
		}
		a /= 10;
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

	cin >> n >> k;
	for(int i = 0; i < k; ++i){
		int d;
		cin >> d;
		s.insert(d);
	}
	
	int ans = n;
	while(!good(ans)){
		ans++;
	}
	cout << ans;
	return 0;
}






