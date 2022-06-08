//C - Snuke Festival:  
//Assunto: 
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int n, j;
ll ans, aux;
map<int, int> maiorA;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    vector<int> a(n), b(n), c(n);
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];
    loop(i, 0, n) cin >> c[i];
    sort(all(a)); sort(all(b)); sort(all(c));
    j = 0;
    loop(i, 0, n) {
        while(b[i] > a[j] and j < n) {
            j++;
        } 
        maiorA[b[i]] = j;
    }
    j = 0; ans = 0; aux = 0;
    loop(i, 0, n) {
        while(c[i] > b[j] and j < n) {
            aux += maiorA[b[j]];
            j++;
        } 
        ans += aux;
    }
    cout << ans << "\n";
}