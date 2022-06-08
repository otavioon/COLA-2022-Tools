#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <functional>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#define	ll long long
#define	ull unsigned long long
#define	vi vector<int>
#define	vll vector<long long>
#define	pii pair<int,int>
#define	pll pair<long long,long long>
#define	PB push_back
#define	MP make_pair
#define	ff first
#define	ss second
#define	IT iterator
#define	IOS ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define	LB cout<<"\n"
#define	CS <<" "<<
#define	DB cout<<"> "
#define	endl "\n"
#define	loop(x,y) for(int x=0;x<y;++x)
#define	loop1(x,y) for(int x=1;x<=y;++x)
#define	MS(x,y) memset(x,y,sizeof(x))

int a[3][3];

int main(){
	loop(i,3) loop(j,3) cin >> a[i][j];
	if((a[0][0]-a[1][0])==(a[0][1]-a[1][1]) && (a[0][1]-a[1][1])==(a[0][2]-a[1][2])
		&& (a[2][0]-a[1][0])==(a[2][1]-a[1][1])&&(a[2][1]-a[1][1])==(a[2][2]-a[1][2]))
		cout << "Yes\n";
	else cout << "No\n";
}