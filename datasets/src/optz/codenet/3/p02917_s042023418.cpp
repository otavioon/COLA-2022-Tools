#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> B[i];
    }

    deque<int> A;
    A.push_back(B[0]);
    A.push_back(B[0]);
    for (int i = 1; i < N - 2; i++)
    {
        if (B[i] > B[i + 1])
        {
            A.push_back(B[i + 1]);
        }
        else
        {
            A.push_back(B[i]);
        }
    }
    A.push_back(B[N - 2]);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += A[i];
    }
    cout << ans << endl;
    return (0);
}