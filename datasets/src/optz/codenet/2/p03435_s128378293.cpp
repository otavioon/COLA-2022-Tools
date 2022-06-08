#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pp = pair<ll,ll>;
const ll amari = 1e9+7;
const char BC = 'A' - 'a';
#define ben(a) a.begin(),a.end() //昇順
#define enb(a) a.rbegin(),a.rend() //降順
#define pb(a,b) a.push_back(b)
//fixed << setprecision(20)
int main(){
	int a,b,c,d,e,f,g,h,i;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	cin >> g >> h >> i;
	int ok = 0;
	int j = a - b;
	int k = d - e;
	int l = g - h;
	if(j != k || k != l || j != l)ok = 1;
	int m = b - c;
	int n = e - f;
	int o = h - i;
	if(m != n || n != o || m != o)ok  = 1;
	int p = a - d;
	int q = b - e;
	int r = c - f;
	if(p != q || q != r || p != r)ok = 1;
	int s = d - g;
	int t = e - h;
	int u = f - i;
	if(s != t || t != u || u != s)ok = 1;

	if(ok)cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}

