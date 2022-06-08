#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <bitset>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<int> q;
    vector<int> visited(N, 0);
    vector<int> an(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> an[i];
    }

    q.push(1);
    visited[1] = 1;

    int cnt = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        ++cnt;
        int next = an[i];
        if (next == 2)
        {
            cout << cnt << endl;
            return 0;
        }
        if (visited[next] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            visited[next] = 1;
        }
        q.push(next);
    }
    return 0;
}