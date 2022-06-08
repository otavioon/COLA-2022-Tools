#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1000000000000
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main(){
  int a[3][3];
  REP(i, 3){
    REP(j, 3){
      cin >> a[i][j];
    }
  }
  int d = a[1][0] - a[0][0];
  int e = a[2][0] - a[1][0];
  if((a[1][1] - a[0][1] == d) && (a[1][2] - a[0][2] == d) && (a[2][1] - a[1][1] == e) && (a[2][2] - a[1][2] == e)) cout << "Yes" << endl;
  else cout << "No" << endl;
	return 0;
}