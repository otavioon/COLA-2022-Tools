#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define sol (k+k)
#define sag (k+k+1)
#define orta ((bas+son)/2)
#define coc g[node][i]
#define mod 1000000007
#define inf 1000000009
#define N 1000005
using namespace std;

typedef long long ll;
typedef pair < int , int > ii;

int n, d, ans, a[N], dp[N];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d %d",&n ,&d);
    int son = 1;
    for(int i = 1; i <= n; i++){
      if(i - son >= d){
        son = i + d + 1;
        ans++;
      }
    }
    if(son <= n)
      ans++;
    printf("%d\n", ans);
    return 0;
}
