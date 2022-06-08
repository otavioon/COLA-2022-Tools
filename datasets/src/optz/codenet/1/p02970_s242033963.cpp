#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

int main() {
    int n,d;
    cin >> n >> d;
    int cnt = d+1;
    int ans=0;
    bool flag = true;
    while (flag){
      cnt += d;
      if (cnt >= n) flag = false;
      ans ++;
      cnt += d+1;
    }
    cout << ans << endl;
}