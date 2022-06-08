#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    cout.precision(18);

    long long N, K;
    set<long long> D;

    cin >> N >> K;
    for (long long i = 0; i < K; i++)
    {
        long long t;
        cin >> t;
        D.insert(t);
    }

    long long i = N;
    while (true)
    {
        long long j = i;
        bool f = false;
        while (j > 0)
        {
            if (D.find(j % 10) != D.end()) // found
            {
                f = true;
                break;
            }
            j /= 10;
        }

        if (f == false)
        {
            cout << i << endl;
            return 0;
        }

        i++;
    }
}