#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1000000007 ))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define bigint __int128
#define sqrt sqrtl
#define cbrt cbrtl
#define endl '\n'
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<float,int> fi;
typedef pair<int,int> ii;
typedef pair<float,float> ff;
typedef vector<ff> vff;
typedef vector<ii> vii;
typedef vector<fi> vfi;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef priority_queue<fi> pqfi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii; 
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi;

	
int32_t main()
{
	IOS
	string s;cin>>s;
	int k;cin>>k;
	if(s.length()==1)
	{
		cout<<k/2<<endl;return 0;
	}
	vector<vector<int>>dp(s.length(),vector<int>(26));
	for(int i=0;i<26;i++)
	dp[0][i]=1;
	dp[0][s[0]-'a']=0;
	for(int i=1;i<s.length();i++)
	{
		multiset<int>st;
		for(int j=0;j<26;j++)
		st.insert(dp[i-1][j]);
		for(int j=0;j<26;j++)
		{
			st.erase(st.find(dp[i-1][j]));
			int mn=*st.begin();
			dp[i][j]=mn+(s[i]-'a'!=j);
			st.insert(dp[i-1][j]);
		}
	}
	/*
	for(int i=0;i<26;i++)
	cout<<(char)(i+'a')<<" ";
	cout<<endl;
	for(int l=0;l<s.length();l++)
	{
		for(int i=0;i<26;i++)
	    cout<<dp[l][i]<<" ";
	    cout<<endl;
	}*/
	int mn1=1e15,mn2=1e15;
	for(int i=0;i<26;i++)
	{
		if(s[0]-'a'!=i)mn1=min(mn1,dp[s.length()-1][i]);
		else mn2=min(mn2,dp[s.length()-1][i]);
	}
	
	cout<<min(mn1*k,mn2*k+k-1)<<endl;
		
	
		
	
	

	
			
}	
 
