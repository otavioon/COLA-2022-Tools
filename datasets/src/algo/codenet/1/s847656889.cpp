#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int c[3][3];
void input()
{
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cin >> c[i][j];
        }
    }
}

void solve()
{
    if ((c[1][0] - c[0][0] != c[1][1] - c[0][1]) || (c[1][2] - c[0][2] != c[1][1] - c[0][1])){
        cout << "No" << endl;
        return;
    }
    if ((c[1][0] - c[2][0] != c[1][1] - c[2][1]) || (c[1][2] - c[2][2] != c[1][1] - c[2][1])){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}