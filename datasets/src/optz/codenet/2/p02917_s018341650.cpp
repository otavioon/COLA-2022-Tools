#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    int N;
    cin >> N;
    vector<int> b;
    int tmp;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    vector<int> a;
    if (b[0] <= b[1])
    {
        a.push_back(b[0]);
        a.push_back(b[0]);
    }
    else
    {
        a.push_back(b[0]);
        a.push_back(b[1]);
    }
    for (int i = 1; i < N - 2; i++)
    {
        if (b[i] > b[i + 1])
        {
            a.push_back(b[i + 1]);
        }
        else
        {
            a.push_back(b[i]);
        }
    }
    a.push_back(b[N - 2]);
    lli ans = 0;
    ans = accumulate(a.begin(), a.end(), 0);
    cout << ans << endl;
    return 0;
}