#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1, (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    int n;
    ull a, b;
    cin >> n >> a >> b;
    ull c = a - b;
    vector<ull> v(n);
    for(auto& i : v){
        cin >> i;
    }
    sort(all(v));
    ull left = 0, right = v.back()/b  + 1;
    while(left <= right){
        ull mid = (left + right)/2;
        ull cnt1 = 0, cnt2 = 0;
        for(auto i : v){
            cnt1 += (i - b*(mid-1) + c - 1)/c;
            cnt2 += (i - b*mid + c - 1)/c;
        }
        if(cnt1 <= mid-1){
            right = mid - 1;
        }else if(cnt2 > mid){
            left = mid + 1;
        }else{
            cout << mid << endl;
            return 0;
        }
    }

    return 0;
}