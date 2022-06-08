#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define re return
#define fi first
#define se second
typedef vector<int> vi; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
int n;
pair<long long,int> p[200010];
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].first;
	}
	sort(p,p+n);
	int ans=0;
	for(int i=n;i--;){
		if(p[i].second)continue;
		long long t=1;
		while(t<p[i].first)t*=2;
		int k=upper_bound(p,p+i,make_pair(t-p[i].first,0) ) - p;
		if(0<k && k<=i && p[i].first+p[k-1].first==t){
			ans++;
			p[k-1].second=1;
		}
	}
	cout<<ans<<endl;
    return 0;
}