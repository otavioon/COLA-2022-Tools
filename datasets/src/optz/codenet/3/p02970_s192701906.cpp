#pragma region _head

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>
#include<regex>

void Init() {
	std::cin.tie(0); std::ios::sync_with_stdio(false);
	struct Init_caller { Init_caller() { Init(); } }caller;
}

#pragma region _define

#define int LL
#define f(i,a,b) for(LL i=a;i<b;i++)
#define rep(i,n) for(LL i=0;i<n;i++)
#define rep2(i,j,a,h,w) for(LL i=0;i<h;i++)for(LL j=0;j<w;j++)cin>>a[i][j]
#define f_vI(v,n) f(i,0,n)cin>>v[i]
#define f_v2I(v1,v2,n) f(i,0,n)cin>>v1[i]>>v2[i]
#define f_v3I(v1,v2,v3,n) f(i,0,n)cin>>v1[i]>>v2[i]>>v3[i]
#define f_vO(v,n) f(i,0,n)cout<<v[i]<<endl
#define ei else if
#define all(a) a.begin(),a.end()
#define size(s) ((LL)s.size())
#define F first
#define S second
#define check() cout<<"! ! !"
#define endl "\n"
#define _y() cout<<"Yes"<<endl
#define _Y() cout<<"YES"<<endl
#define _n() cout<<"No"<<endl
#define _N() cout<<"NO"<<endl
#define INT_INF 1<<29
#define LL_INF 1LL<<60
#define MOD 1000000007

#pragma endregion





#pragma region _using

using namespace std;

using LL = long long;
using st = string;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<st>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using qi = queue<int>;
using qc = queue<char>;
using qs = queue<st>;
using si = stack<int>;
using sc = stack<char>;
using ss = stack<st>;
using pi = pair<int, int>;
using ppi = pair<pi, int>;
using mii = map<int, int>;
using mib = map<int, bool>;
using mci = map<char, int>;
using msb = map<st, bool>;
using vpi = vector<pi>;
using vppi = vector<ppi>;
using qpi = queue<pi>;

#pragma endregion

//4,2,8,6,1,7,3,9
int arround_x[] = { -1,0,0,1,-1,-1,1,1 };
int arround_y[] = { 0,1,-1,0,1,-1,1,-1 };



void y_n(bool p) {
	p ? _y() : _n();
}

void Y_N(bool p) {
	p ? _Y() : _N();
}

LL vmax(vi v, LL n) {
	int MAX = 0;
	f(i, 0, n) {
		MAX = max(MAX, v[i]);
	}
	return MAX;
}

LL vmin(vi v, LL n) {
	int MIN = LL_INF;
	f(i, 0, n) {
		MIN = min(MIN, v[i]);
	}
	return MIN;
}

LL gcd(LL a, LL b) {
	if (b == 0) {
		swap(a, b);
	}
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b) * b);
}

bool is_square(int n) {
	if ((int)sqrt(n)*(int)sqrt(n) == n) {
		return true;
	}
	else {
		return false;
	}
}

//�f������
bool is_prime(int n) {
	if (n == 1) {
		return false;
	}
	else {
		for (int i = 2; i*i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}


//�f��������
void dec_prime(int n) {
	int a = 2;
	while (a*a <= n) {
		if (n % a == 0) {
			cout << a << endl;
			n /= a;
		}
		else {
			a++;
		}
	}
	cout << n << endl;
}

//�G���g�X�e�l�X��� �i���[a,b]��⿁j
int sieve_prime(LL a,LL b) {
	if (a > b)swap(a, b);
	vb s(b + 1, true);
	int cnt_a=0,cnt_b = 0;
	f(i, 2, b + 1) {
		for (int j = 2; i*j <= b; j++) {
			s[i*j] = false;
		}
	}
	//cout << "2����" << n << "�܂ł̑f��" << endl;
	f(i, 2, b + 1) {
		if (s[i]) {
			//cout << i << " ";
			if (i < a) {
				cnt_a++;
			}
			cnt_b++;
		}
	}
	return cnt_b - cnt_a;
}

//�K��v�Z
LL factorial(LL n) {
	LL a = 1, ret = 1;
	while (a < n) {
		a++;
		ret *= a;
		ret %= MOD;
	}
	return ret;
}


#pragma endregion 

vi par;

int root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = root(par[x]);
	}
}

void unite(int x, int y) {
	if (root(x) == root(y)) {
		return;
	}
	else {
		par[root(x)] = root(y);
		return;
	}
}

bool same(int x, int y) {
	return root(x) == root(y);
}

struct edge {
	int to;
	int cost;
};

/*****************************************************************************/
signed main() {

	int n, d;
	cin >> n >> d;
	cout << ceil((double)n / (double)(2 * d + 1));

	return 0;
}