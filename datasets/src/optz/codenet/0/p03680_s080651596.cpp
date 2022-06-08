#include <bits/stdc++.h>
#define ll long long
#define li long int
#define ld long double
#define pl pair<long long, long long>
#define pi pair<int, int>
#define ppl pair<pl, ll>
#define ppi pair<int, pi>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LLFOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define MOD 1000000007
#define M2 998244353
//std::cout <<setprecision(30) << av << endl;
using namespace std;
int a[300000];
bool vis[300000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    FOR(i, 1, n+1){
        cin >> a[i];
        vis[i]=0;
    }
    int y=1;
    int cnt=0;
    while(vis[y]==0&&y!=2){
        vis[y]=1;
        cnt++;
        y=a[y];
    }
    if(vis[y]==1){
        cout << "-1" << endl;
    }else{
        cout << cnt << endl;
    }


}
