#include <iostream>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)

int main()
{

    double N, D;
    cin >> N >> D;

    rep(i, 20)
    {
        if (N / (2 * D + 1) <= i)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}