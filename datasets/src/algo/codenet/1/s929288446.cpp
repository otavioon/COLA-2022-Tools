#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define ROF(i,b,a) for (int i=(b);i>(a);--i)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,n-1,-1)

typedef int i32;
typedef long long int i64;
typedef unsigned long long int ui64;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef pair<int,int> Pi;

constexpr int INF = 1e9 + 7;
constexpr int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
    int tmp,sum=0; REP(i,3) REP(j,3) {
        cin >> tmp;
        sum += tmp;
    }
    string ans = (sum%3==0)?"Yes":"No";
    cout<<ans<<endl;
}
