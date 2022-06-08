#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

vector<ll> vd;

void calcDivisor(ll n){

    set<ll> sttemp, st;

    ll iend = sqrt(n) + 1;
    for(int i=1; i<=iend; i++){
        if(n % i == 0){
            sttemp.insert(i);
        }
    }

    for(ll x : sttemp){
        st.insert(x);
        st.insert(n/x);
    }

    for(ll x : st){
        vd.push_back(x);
    }

    sort(vd.begin(), vd.end());
    return;
}

int calcDigits(ll n){

    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10;
    }

    return cnt;
}

int main(){

    ll n; cin >> n;

    calcDivisor(n);

    int vmin = 1e9;
    for(auto x : vd){
        if(x > sqrt(n) + 1){
            break;
        }
        
        vmin = min(vmin, max(calcDigits(x), calcDigits(n/x)));
    }

    cout << vmin;

    return 0;
}