#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;
#define tr(container, it) \
        for (auto it = container.begin(); it != container.end(); it++)
#define scontains(c, x) ((c).find(x) != (c).end())   //O(log n)
#define contains(c, x) (find((c).begin(),(c).end(),x) != (c).end()) //O(n)
#define ill(_x)  ll _x;scanf("%lld",&_x);
#define idb(_x)  double _x;scanf("%lf",&_x);
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vs vector<string>
#define in0(x, a, b)((x)>=a && (x)<=b    )
#define in1(x, a, b)((x)>a && (x)<b)
#define  rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const double pi = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const int X10=1024,X11=2048,X12=4096,X13=8196,X14=16392,X15=32786,X16=65536,X17=131072,X18=262144,X19=524288,X20=1048576;

pair<int,int> f(int a1,int a2,int a3){
    return {a1-a2,a2-a3};
};
int A[263];
void _(){
   int a1, a2, a3, a4, a5, a6, a7,a8, a9;
   cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6>> a7 >> a8 >> a9;
   if(f(a1,a2,a3)==f(a4,a5,a6) && f(a4,a5,a6)==f(a7,a8,a9))cout << "Yes";
   else cout << "No";
}






int main() {
#ifdef Debug
    freopen("/home/joduskame/Desktop/cpp/IO/Input.txt", "r", stdin);
    freopen("/home/joduskame/Desktop/cpp/IO/Output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    _();
    return 0;

}






