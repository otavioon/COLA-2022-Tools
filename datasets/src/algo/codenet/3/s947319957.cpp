#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i =0; i < n ;i++)
using namespace std;

const int max_n = 100003;
int A[max_n], B[max_n], C[max_n];
//int A_M[max_n], B_M[max_n]; 

int main(){
    int N;
    long long ans = 0;
    cin >> N;

    rep(i, N) cin >>A[i];
    rep(i, N) cin >>B[i];
    rep(i, N) cin >>C[i];
    std::sort(A, A+N);
    std::sort(B, B+N);
    std::sort(C, C+N);

    rep(i, N){
        //if(A_M[i] > 0) ans += A_M[i];
        //else if(A_M[i]==0){
        rep(j, N){
            //if(B_M[j] > 0) ans += B_M[j];
            //else if(A[i]<B[j] && B[j]==0){
            if(A[i]<B[j]){
                rep(k, N){
                    //
                    //cout << ans << endl;
                    //if(B[j] < C[k]) B_M[j]++;
                    if(B[j] < C[k]) ans++;
                }
                //ans += B_M[j];
                //if(B_M[j]==0) B_M[j] =-1;
            }  
            //}
        }
    }

    cout << ans << endl;
    return 0;
}