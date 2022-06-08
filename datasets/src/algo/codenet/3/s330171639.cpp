/* Author haleyk10198 */
/* 作者:  haleyk10198 */
/* CF handle: haleyk100198*/
/* FOR ACM-ICPC WF*/
#include <bits/stdc++.h>

#define MOD 1000000007
#define LINF (1LL<<60)
#define INF 2147483647
#define PI 3.1415926535897932384626433
#define ll long long
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define vi vector<int>
#define vvi vector<vi>
#define EPS 1e-9

using namespace std;

int n, a[100010], b[100010], c[100010];
ll rb[100010], pb[100010];

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	for(int i = 0; i < n; i++)
		cin >> c[i];
	
	sort(a, a+n), sort(b, b+n), sort(c, c+n);
	
	for(int i = 0, j = 0; i < n; i++){
		while(j < n && b[i] >= c[j])
			j++;
		rb[i] = n-j;
	}
	
	ll tot = accumulate(rb, rb+n, 0LL);
	ll res = 0;
	
	for(int i = 0, j = 0; i < n; i++){
		while(j < n && a[i] >= b[j])
			tot -= rb[j++];
		res += tot;
	}
	
	cout << res << endl;
	return 0;
}
