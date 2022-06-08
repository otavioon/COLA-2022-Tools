#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n,d;
    cin >> n >> d;
    int range = (n+d) - (n-d) + 1;
    int ans = 0 , flag = 0;
    for(int i=1;i<100;i++){
        range = range * i;
        ans++;
        if(range>=n){
            break;
        }
    }
    
    cout << ans << endl;
    
}