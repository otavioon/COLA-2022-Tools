#include <iostream>
#include <vector>
#include <tuple>


using namespace std;


using ll = long long;


bool check(ll grid[][3], tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
{
    ll as[3];
    ll bs[3];

    as[0] = get<0>(a); as[1] = get<1>(a); as[2] = get<2>(a);
    bs[0] = get<0>(b); bs[1] = get<1>(b); bs[2] = get<2>(b);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != as[i] + bs[j]) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    vector<tuple<ll, ll, ll>> a;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            for (int k = 0; k <= 100; k++)
                a.push_back(make_tuple(i, j, k));

    ll grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    bool feasible = false;
    for (auto t : a) {
        ll b1, b2, b3;
        b1 = grid[0][0] - get<0>(t);
        b2 = grid[1][1] - get<1>(t);
        b3 = grid[2][2] - get<2>(t);
        if (check(grid, t, make_tuple(b1, b2, b3))) {
            feasible = true;
            break;
        }
    }
    if (feasible)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
