#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort
#include <map> // pair
#include <queue>
#include<iomanip>
#include <cmath>
#include <set>

#define ABS(x) ((x)>0?(x):-(x))
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

#define INF 1000000000

using namespace std;
typedef long long ll;

ll newton(long long int a, long long int  b)
{
	if(a==b)
		return a;
	while(a != 0 && b != 0)
	{
		if(a > b)
		{
			b += a;
			a = b-a;
			b -= a;
		}
		b %= a;
	}
	return a;
}

struct UnionFind {
	vector<int> p;
	UnionFind(int N):p(N)
	{
		for(int i=0; i< N; i++)
		{
			p[i] = i;
		}
	}
	int root(int x)
	{
		if(p[x] == x)
			return x;
		return p[x] = root(p[x]);
	}
	void unite(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		if(rx == ry) return;
		p[rx] = ry;
	}
	bool issame(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

//大きな数に対する割り算をするとき、MODを指定することで掛け算の値に変換できる

ll div2mul_calc(ll a, ll b, ll m)
{
	if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        ll d = div2mul_calc(a, b / 2, m);
        return (d * d) % m;
    } else {
        return (a * div2mul_calc(a, b - 1, m)) % m;
    }
}
ll div2mul(ll n, ll mod)
{
	return div2mul_calc(n, mod-2, mod);
}

ll twoRow(ll a, ll b, ll mod)
{
	ll ret = 1;
	for(ll i = 1 ;i <= a+b;++i)
	{
		ret *= i;
		ret %= mod;
	}
	for(ll i = 1 ;i <= a;++i)
	{
		ret *= div2mul(i,mod);
		ret %= mod;
	}
	for(ll i = 1 ;i <= b;++i)
	{
		ret *= div2mul(i,mod);
		ret %= mod;
	}
	return ret;
}

struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return (ret);
}

	vector<int> r[200010];
	ll add[200010] = {0};
	ll point[200010] = {0};
	int visited[200010] = {0};
int main()
{
	ll N,Q;
	string S;
	ll i,j,k;
	queue<int> pos;
	cin >> N >>Q;
	for(i=0;i<N-1;++i)
	{
		cin>>j>>k;
		--j;--k;
		r[j].push_back(k);
		r[k].push_back(j);
	}
	for(i=0;i<Q;++i)
	{
		cin>>j>>k;
		add[j-1] += k;
	}
	pos.push(0);
	while(!pos.empty())
	{
		int cur = pos.front();
		pos.pop();
		visited[cur] = 1;
		point[cur] = add[cur];
		for(j=0;j<r[cur].size();++j)
		{
			k = r[cur][j];
			if(!visited[k])
			{
				pos.push(k);
				add[k] += add[cur];
			}
		}
	}
	for(i=0;i<N;++i)
	{
		cout << point[i] << " ";
	}
	cout << endl;
	return 0;
}


















