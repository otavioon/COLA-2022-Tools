#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,i,j,k,ans = 0;
    cin >> N;
    int A[N],B[N],C[N];;
    for(i = 0;i < N;i++){
        cin >> A[i];
    }
    for(i = 0;i < N;i++){
        cin >> B[i];
    }
    for(i = 0;i < N;i++){
        cin >> C[i];
    }
    sort(A,A + N);
    sort(B,B + N);
    sort(C,C + N);
    for(i = 0;i < N;i++){
        for(j = 0;B[j] < C[i] && j < N;j++){
            for(k = 0;A[k] < B[j] && k < N;k++){
                ans++;
            }
        }
    }
    cout << ans << endl;
}