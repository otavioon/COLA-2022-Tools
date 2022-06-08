#include <bits/stdc++.h>
using namespace std;

long lb(unsigned long a){
    long ret = 0;
    for(long s=32; s>0; s>>=1){
        if(a>>s){
            a >>= s;
            ret += s;
        }
    }
    return ret;
}

int main(void){
    long n;
    cin >> n;
    multiset<long> s;
    for(long i=0; i<n; i++){
        long t;
        cin >> t;
        s.insert(t); 
    }
    long cnt = 0;
    while(!s.empty()){
        const auto ix = max_element(s.begin(), s.end());
        const auto y = (1l << lb(*ix<<1))-*ix;
        s.erase(ix);
        const auto iy = s.find(y);
        if(iy!=s.end()){
            s.erase(iy);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
