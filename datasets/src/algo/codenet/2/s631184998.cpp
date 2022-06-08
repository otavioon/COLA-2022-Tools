#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    multiset<long long int> num;
    for(int i=0; i<n; i++){
        long long int a;
        cin >> a;
        num.insert(a);
    }

    long long int ans = 0;
    while(num.empty() == false){
        long long int x = *prev(num.end());
        num.erase(num.find(x));

        long long int y = 1;
        while(y <= x) y *= 2;
        //cout << x << " " << y << endl;

        if(num.empty() == false
        && num.find(y - x) != num.end()){
            ans += 1;
            num.erase(num.find(y - x));
        }
    }
    cout << ans << endl;
    return 0;
}