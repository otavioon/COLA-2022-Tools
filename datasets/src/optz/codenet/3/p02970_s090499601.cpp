#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n,v) rep(i,n) cin >> v[i]
using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
int x_pos[4] = {1,0,-1,0}, y_pos[4] = {0,1,0,-1};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

char upper(char c){
	return c-0x20;
}

char lower(char c){
	return c+0x20;
}

void unique_vector(vector<int>& v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    int n,d;cin>>n>>d;
    int ans = n/(2*d);
    if(n%(2*d+1)!=0)ans++;
    cout << ans << endl;
}

