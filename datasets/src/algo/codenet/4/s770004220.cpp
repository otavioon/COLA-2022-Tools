#include <bits/stdc++.h>

using namespace std;

set<int> s;

bool check(int n){
    while(n){
        if(s.count(n%10)){
            return false;
        }
        n/=10;
    }    
    return true;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;


    int x;

    for(int i=0;i<k;++i){
        cin >> x;
        s.insert(x);
    }

    while(1){
        if(check(n)){
            cout << n << '\n';
            break;
        }
        n++;
    }

    return 0;
}