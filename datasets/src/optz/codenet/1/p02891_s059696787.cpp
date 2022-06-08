#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    long long k;
    cin >> str;
    cin >> k;
    long long n = str.size();
    bool check = true;
    for(int i = 1; i < n; i++){
        if(str[i] != str[i - 1]){
            check = false;
            break;
        }
    }
    if(check){
        cout << n * k / 2 << "\n";
        return 0;
    }
    check = str[0] == str.back();
    long long ans = 0, cnt = 1;
    for(int i = 1; i < n; i++){
        if(str[i - 1] == str[i]){
            cnt++;
        }else{
            ans += k * (cnt / 2);
            cnt = 1;
        }
    }
    ans += k * (cnt / 2);
    if(check){
        long long a = 0, b = 0;
        for(int i = 0; str[i] != str[0]; i++){
            a++;
        }
        for(int i = n - 1; str[i] != str[0]; i--){
            b++;
        }
        ans -= (k - 1) * ((a / 2) + (b / 2) - ((a + b) / 2));
    }
    cout << ans << "\n";
}

