#include <iostream>
using namespace std;
int main(void){
    int k, len;
    long long ans = 0;
    string s;
    cin >> s >> k;
    len = s.length();
    if(k == 1){
        for(int i=1;i<len;i++){
            if(s[i] == s[i-1]){
                ans++;
                s[i] = '.';
            }
        }
    }else{
        int u = -1;
        for(int i=1;i<len;i++){
            if(s[i] != s[i-1]){
                u = i;
                break;
            }
        }
        if(u == -1){
            ans = (long long)k*len;
            ans /= 2;
        }else{
            string t = s.substr(u) + s.substr(0, u);
            //cout << t << endl;
            for(int i=1;i<len;i++){
                if(t[i] == t[i-1]){
                    ans++;
                    i++;
                }
            }
            ans *= (long long)k;
        }
    }
    cout << ans << endl;
}
