#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
    string str;
    cin >> str;
    LL k, len = str.length();
    cin >> k;
    if(str[len - 1] != str[0]) {
        LL ans = 0, counter = 1;
        for(int i = 1; i < len; i++) {
            if(str[i] == str[i - 1]) {
                counter++;
            }
            else {
                ans += (counter / 2);
                counter = 1;
            }
        }
        ans += (counter / 2);
        cout << ans * k << endl;
    }
    else {
        LL counter = 1, ans = 0;
        for(int i = 1; i < len; i++) {
            if(str[i] == str[i - 1]) counter++;
            else counter = 1;
        }
        if(counter == len) {
            LL t = len * k;
            cout << t / 2LL << endl;
            return 0;
        }
        counter = 1;
        for(int i = 1; i < len; i++) {
            if(str[i] == str[i - 1]) {
                counter++;
            }
            else {
                ans += (counter / 2);
                counter = 1;
            }
        }
        ans += (counter / 2);
        LL flag = 0, idx = 0, cur = 0;
        while(idx < len && str[idx] == str[0]) {
            idx++;
        }
        flag = flag | (idx % 2 == 0);
        idx = len - 1;
        while(idx >= 0 && str[idx] == str[len - 1]) {
            idx--;
            cur++;
        }
        flag = flag | (cur % 2 == 0);
        // if(!flag) {
        //     ans++;
        // }
        cout << ans * k << endl;
    }
    return 0;
}