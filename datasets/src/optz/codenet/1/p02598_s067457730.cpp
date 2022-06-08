#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
 
#define ff                  first
#define ss                  second
#define endl                "\n"
#define loop(i,s,e)         for(int i=s;i<e;i++)
#define int                 long long
#define vi                  vector<int> 
#define S(v)                sort(v.begin(),v.end())
#define RS(v)               sort(v.rbegin(),v.rend())
#define R(v)                reverse(v.begin(),v.end())
#define mxpq(T)             priority_queue <T>
#define mnpq(T)             priority_queue<T,vector<T>,greater<T>>
#define prv(v)              for(auto &x : v)cout << x << " ";
#define piirv(v)            for(auto &x : v)cout << x.ff << " " << x.ss << endl;
#define prvv(v)             for(auto &x : v)for(auto &y : x.ss)cout << y << " ";
#define mp                  make_pair
#define pii                 pair<int,int>
#define mset(a,f)           memset(a , f , sizeof(a))
#define pb                  push_back
#define inf                 INT_MAX
#define INF                 LLONG_MAX
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
 
const int N = 2e6 + 6;
const int M = 1e9+7;
int A[N];
int n , k;

bool check(int x)
{
	int op = 0;	

	loop(i,0,n)
	{
		if(A[i] < x)continue;
		int rt = (A[i]/x);
		if(A[i]%x)rt++;
		op += (rt-1);
	}

	return op <= k;
}

void solve()
{
	cin >> n >> k;

	loop(i,0,n)cin >> A[i];

	int st = 0  , en = 1e10;

	int ans = 0;

	while(st <= en)
	{
		int mid = (st+en)/2;
		if(check(mid))
		{
			ans = mid;
			en = mid-1;
		}
		else st = mid+1;
	}

	cout << ans;
}			
 
int32_t main()
{
 
cout<<fixed<<setprecision(16);
 
ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
 	
 
 	int t = 1;
 	// cin >> t;
 	while(t--)solve();
  
}