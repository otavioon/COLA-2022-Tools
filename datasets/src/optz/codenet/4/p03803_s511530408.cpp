#include "bits/stdc++.h"
 
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define REREP(i,n) for(int i=int(n-1); i>=0; i--)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define REFOR(i,m,n) for(int i=int(n-1); i>=int(m); i--)
#define ALL(obj) (obj).begin(),(obj).end()
 
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VD vector<double>
#define VVD vector<vector<double>>
#define VVVD vector<vector<vector<double>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VVVL vector<vector<vector<ll>>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define VVVB vector<vector<vector<bool>>>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVVS vector<vector<vector<string>>>
 
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<ll,ll>
#define VPII vector<pair<int,int>>
#define VVPII vector<vector<pair<int,int>>>
#define VVVPII vector<vector<vector<pair<int,int>>>>
#define VPLL vector<pair<ll,ll>>
#define VVPLL vector<vector<pair<ll,ll>>>
#define VVVPLL vector<vector<vector<pair<ll,ll>>>>
 
#define SUMI(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SUMD(obj) accumulate((obj).begin(), (obj).end(), 0.)
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0LL)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

#define PB push_back
#define Cout(str) cout << str << endl

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const ll EPS = (ll)1e-8;

int main(){
	int n,m;
	int a,b,c,d;
	int sum;
	string str;
	string s,t;
	char ch;
	VI vi;
	vector<char> vc;
	VS vs;
	int reserve_vi = 100;
	map<int, int> table; 
	string str2, str3;
	map<char, string> vowel;
	vector<char> vowel_vec = {'a', 'e', 'i', 'o', 'u'};

	//cin >> n >> m;
	cin >> a >> b;
	//cin >> a >> b >> c;
	//cin >> a >> b >> c >> d;
	//cin >> str;
	//cin >> str >> str2 >> str3;
	//cin >> n;
	
	//cin >> s >> t;
	//cin >> ch;
	//cin >> a >> ch >> b;
	
	a += 11;
	b += 11;
	a %= 13;
	b %= 13;
	if(a < b) cout << "Bob" << endl;
	else if(a == b) cout << "Draw" << endl;
	else cout << "Alice" << endl;
	//cout << accumulate(vi.begin(), vi.begin()+n, 0) << endl;
	//replace(ALL(str), ',', ' ');

	//swap(a, b);
	//vi.resize(N);
	//fill(vi.begin(), vi.end(), 1);
	//vi.reserve(reserve_vi);
	//vi.PB(n);

	//vc.resize(5);
	//vc[i] = (str[i]);

	//sort(vc.begin(), vc.end(), greater<char>());
	//sort(vc.begin(), vc.end());

	//for(auto itr = table.begin(); itr != table.end(); ++itr) {
	return 0;
}

