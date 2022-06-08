#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int A[100000], B[100000], C[100000];

    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &A[i]);
    for (int i=0; i<n; i++) scanf("%d", &B[i]);
    for (int i=0; i<n; i++) scanf("%d", &C[i]);

    sort(A, A+n); sort(B, B+n); sort(C, C+n);

    int tB[100000], tC[100000];
    for (int pa=0, pb=0; pb<n; pb++) {
        while (A[pa]<B[pb] && pa<n) pa++;
        tB[pb] = pa;
    }

    long long int res = 0;
    for (int pb=0, pc=0, sum=0; pc<n; pc++) {
        while (B[pb]<C[pc] && pb<n) {
            sum += tB[pb];
            pb++;
        }
        res += sum;
    }

    cout << res << endl;

    return 0;
}