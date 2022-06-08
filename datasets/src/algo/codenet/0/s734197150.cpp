#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    int n = s.length();
    if(n == 1){
        cout << k/2 << endl;
        return 0;
    }
    bool same = true;
    for(char c : s) same &= c == s[0];
    if(same){
        cout << k*(n)/2 << endl;
        return 0;
    }
    ll ans = 0;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && s[j] == s[i])   j++;
        ans += (j-i)/2;
        i = j;
    }
    ans *= k;
    if(s[0] == s.back() && k > 1){
        int i = 0, j = n-1;
        while(s[0] == s[i]) i++;
        while(s[0] == s[j]) j--;
        ans -= (i/2+(n-1-j)/2)*(k-1);
        ans += (i+n-1-j)/2*(k-1);
    }
    cout << ans << endl;
    return 0;
}