#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-10;
const vi emp;

int Figure(ll x){
	return to_string(x).size();
}

int n,k;
set<int> st;

bool func(int x){
	int F=Figure(x),tmp=1;
	for(int i=0;i<F;i++){
		if(st.find(x/tmp%10)!=st.end()) return 0;
		tmp*=10;
	}
	return 1;
}

int main(){
	cin>>n>>k;
	int a;
	for(int i=0;i<k;i++){
		cin>>a;
		st.insert(a);
	}
	int ans=n;
	while(1){
		if(func(ans)) break;
		ans++;
	}
	cout<<ans<<endl;
}