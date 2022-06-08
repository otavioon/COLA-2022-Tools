#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define all(x) x.begin(),x.end()
#define ii int,int 
#define mm map<ii>
#define ff first    
#define ss second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define forv(i,m) for(auto i : m)
#define imx INT_MAX
#define imn INT_MIN
#define inf LONG_MAX
#define minf LONG_MIN
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sze size()
#define rvs reverse 
#define itr iterator 

/*
#define MODM(a,b,md) ((a%md)*(b%md))%md
#define MODA(a,b,md) ((a%md)+(b%md))%md
#define ull unsigned long long int
#define si short int
*/

/*
bool compare(int a,int b) {return a > b;}
bool compare1(ppi a,ppi b) {return a.ff > b.ff;}
bool compare2(ppi a,ppi b) {return a.ss < b.ss;}
ll Npower(ll a,ll b) {ll product = 1; while(b){if(b&1){product = product*a;}a = a*a;b = b>>1;} return product;}
ll power(ll a,ll b,ll md) {ll product = 1; while(b){if(b&1){product = MODM(product,a,md);}a = MODM(a,a,md);b = b>>1;} return product%md;}
ll GCD(ll a,ll b) {return b==0 ? a:GCD(b,a%b);}
ll LCM(ll a,ll b) {return (a/GCD(a,b))*b; }
*/


int main()
{
	fast

	int n,d;
	cin>>n>>d;


	int val = (n-(d+1))/(2*d+1) + 1;
	int last = (d+1) + (val-1)*(2*d+1);

	if((last + d)  < n)
	{
		val++;
	}

	cout<<val;

	return 0;
}