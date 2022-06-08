#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int N;
int A[100010];
int B[100010];
int C[100010];

int main() {
    cin >> N;
    rep(i, N) scanf("%d", &A[i]);
    rep(i, N) scanf("%d", &B[i]);
    rep(i, N) scanf("%d", &C[i]);

    sort(A, A+N);
    sort(B, B+N);
    sort(C, C+N);

    int cnt = 0;
    int j, k;
    rep(i, N) {
        for(j=0; j < N; j++) {
            if(B[j] <= A[i]) continue;
            for(k = 0; k < N; k++) {
                if(C[k] <= B[j]) continue;
                cnt += N-k;
                break;
            }
        }
    }
    cout << cnt << endl;
}
