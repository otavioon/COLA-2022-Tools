#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
const int INF = 1e9;
const ll mod = 1000000007;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b / gcd(a,b);}

int main() {
    int a,b;
    cin >> a >> b;
    vector<int> vc = {2,3,4,5,6,7,8,9,10,11,12,13,1};
    vector<int>::iterator itr_a = find(vc.begin(), vc.end(), a);
    vector<int>::iterator itr_b = find(vc.begin(), vc.end(), b);
    int index_a = distance(vc.begin(), itr_a);
    int index_b = distance(vc.begin(), itr_b);
    if (index_a > index_b) {
        cout << "Alice" << "\n";
    }
    if (index_b > index_a) {
        cout << "Bob" << "\n";
    }
    if (index_a == index_b) {
        cout << "Draw" << "\n";
    }
}
