#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e8;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-16;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};


int n, k;
bool bad[10];
bool check(int x){
    string s = to_string(x);
    for (int i = 0; i < s.length(); i++)
        if (bad[s[i] - '0']) return false;
        return true;
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        bad[x] = true;
    }
    for (int i = n; i <= 10 * n + 1; i++){
        if (check(i)){
            cout << i << endl;
            return;
        }
    }
}
/*
 4 4
 abdc
 defg
 aefg
 bdce
 */
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(7);
    //freopen("inevit.in", "r", stdin);
    //freopen("inevit.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();

}