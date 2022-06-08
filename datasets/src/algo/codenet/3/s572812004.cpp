//ABC084 - C
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N], B[N], C[N];
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
    for(int i=0;i<N;i++) cin >> C[i];
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);
    int ans = 0;

    int d = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i]<B[j]){
                for(int k=d;k<N;k++){
                    if(B[j]<C[k]){
                        ans += N - k;
                        d = k;
                        break;
                    }
                }
            }
        }
    }




    /*
    int ab[N], bc[N];
    for(int i=0;i<N;i++){
        ab[i] = N;
        bc[i] = N;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i]<B[j]){
                ab[i] = j;
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(B[i]<C[j]){
                bc[i] = j;
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=ab[i];j<N;j++) {
            ans = ans + (N - bc[j]);
        }
    }*/
    cout << ans << "\n";
    return 0;
}