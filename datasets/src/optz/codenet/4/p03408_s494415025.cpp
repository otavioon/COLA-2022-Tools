#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    set<string> U;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        U.insert(S[i]);
    }
    int M;
    cin >> M;
    vector<string> T(M);
    for (int i = 0; i < M; i++)
    {
        cin >> T[i];
        U.insert(T[i]);
    }
    int ans = 0;
    for (string str : U)
    {
        int s, t;
        s = count(S.begin(), S.end(), str);
        t = count(T.begin(), T.end(), str);
        if ((0 < (s - t)) && (ans < (s - t)))
        {
            ans = s - t;
        }
    }
    cout << ans << endl;

    return 0;
}