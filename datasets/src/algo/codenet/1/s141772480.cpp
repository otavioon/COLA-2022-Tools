#include <iostream>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 1; i <= n; i++)
using namespace std;
static const int Nil = -1;
static const int Inf = 1 << 30;

int main()
{
    int C[9];
    REP(i, 9)
    {
        cin >> C[i];
    }
    int a2 = C[3] - C[0];
    int a3 = C[6] - C[0];
    int b2 = C[1];
    int b3 = C[2];
    if (a2 + b2 != C[4])
        cout << "No" << endl;
    else if (a3 + b2 != C[7])
        cout << "No" << endl;
    else if (a2 + b3 != C[5])
        cout << "No" << endl;
    else if (a3 + b3 != C[8])
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
