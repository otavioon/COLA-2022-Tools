#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const int p = 1000000009;
int lowbit(int x){ return x & (-x);}
int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p;} return x % p;}

int main(){
	int x, y;
	scanf("%d%d", &x, &y);
	if(x * 500 >= y) puts("Yes");
	else puts("No");
    return 0;
}
