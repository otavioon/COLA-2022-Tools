#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    multiset<long long> ms;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        ms.insert(x);
    }
    long long t = 1;
    auto itr = --ms.end();
    while(*itr > t) t <<= 1;
    while(!ms.empty()){
        itr = --ms.end();
        long long x = *itr;
        while(2 * x < t) t >>= 1;
        ms.erase(itr);
        auto itr2 = ms.find(t - x);
        if(itr2 != ms.end()){
            ans++;
            ms.erase(itr2);
        }
    }
    cout << ans << endl;
    return 0;
}
