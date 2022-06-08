#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int c[3][3];
    int ans = 0;
    int res = 0;
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
            ans += c[i][j];
        }
    }   
    rep(i, 3){
        rep(j, 3){
            if(i==j)
                res += c[i][j];
        }
    }
    

    if(ans == 3 * res){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    return 0;
}