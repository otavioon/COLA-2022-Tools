#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<fstream>
#include<cstdio>
#include<deque>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(g);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
const double PI = acos(-1.0);

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<ll> dll;
ll mod = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long c[3][3], sum = 0, s1, s2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
			sum += c[i][j];
		}
	}
	s1 = c[0][0] + c[1][1] + c[2][2];
	s2 = c[0][2] + c[1][1] + c[2][0];
	if (sum == s1 * 3 && sum == s2 * 3)
		puts("Yes");
	else
		puts("No");
	return 0;
}