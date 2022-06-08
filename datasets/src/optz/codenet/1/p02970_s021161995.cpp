#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;

    int ans = 0;
    int st = 1;
    while(1){
        st += (d * 2);
        st++;
        ans++;
        if((n - st) <= d){
            ans++;
            break;
        }
    }

    cout << ans << endl;
}