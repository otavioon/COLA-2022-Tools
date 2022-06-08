#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair <int, int>
#define sz(a) (int)(a.size()) 
#define resize(v) v.resize(unique(all(v)) - v.begin()); 
#define all(a) a.begin(), a.end()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)

using namespace std;

void Fast_Read_Out()
{
	ios_base::sync_with_stdio(0);
	cin.tie(), cout.tie();
}

void Random()
{
	unsigned int seed;
	asm("rdtsc" : "=A" (seed));
	srand(seed);        
}

unsigned int Time()
{
	 unsigned int time = clock() / 1000.00;
	 return time;
}

const int inf = int(1e9) + 123;
const int N = int(1e5) + 213;

int a[N], b[N], c[N];
vector <int> vc, va;

int main ()
{
	#ifdef JUDGE
		freopen("input.txt", "r", stdin);
	#endif 
	Random();
	Fast_Read_Out();
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++)
	{
		va.pb(a[i]);
		vc.pb(c[i]);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = b[i];
		int amount_a = lower_bound(all(va), cur) - va.begin();
		int amount_c = vc.end() - (upper_bound(all(vc), cur));
		ans += amount_a * amount_c;
	}
	cout << ans;
	#ifdef JUDGE
//		cout << Time() << endl;
	#endif
}
// Easy Peasy Lemon Squeezy