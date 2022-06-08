#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
#include<cmath>
#include<iomanip>
#include<iterator>
#include<queue>
#include<stack>
#include<cctype>
#include<deque>
#include<time.h>
#include<bitset>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
//by Skeef79

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define en '\n'
#define for0(i,n) for(int i = 0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vec vector
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

const int INF = 2000000000;
const ll LINF = 2000000000000000000;

template<typename T> void print(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}

template<typename T> void print(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}

template<typename T> void print(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}

template <typename T> void input(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}

template<typename T> void input(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}

template<typename T> void input(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			cin >> a[i][j];
}


void solve()
{
	ll k, x;
	cin >> k >> x;
	if (k * 500 >= x)
		cout << "Yes";
	else
		cout << "No";
	 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int tst = 1;
	//cin >> tst;
	while (tst--)
		solve();
}