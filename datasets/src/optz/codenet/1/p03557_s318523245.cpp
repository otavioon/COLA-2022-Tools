#include <iostream>
using namespace std;

int main() {
    int N;
    int cnt = 0;
    cin >> N;
    int A[N];
    int B[N];
    int C[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++)
        cin >> C[i];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(A[i] < B[j] && B[j] < C[k])
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
