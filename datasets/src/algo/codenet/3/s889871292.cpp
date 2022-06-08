#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[N];
    int B[N];
    int C[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    long long ans = 0;
    long long idxA = 0;
    long long idxC = 0;

    for (int i = 0; i < N; i++)
    {
        while (idxA < N && A[idxA] < B[i])
        {
            idxA++;
        }
        while (idxC < N && B[i] >= C[idxC])
        {
            idxC++;
        }
        ans += idxA * (N - idxC);
    }
    cout << ans << endl;
}
