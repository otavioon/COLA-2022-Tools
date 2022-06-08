#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <numeric>
#include <climits>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int N;
    int cnt = 0;
    cin >> N;
    int A[N], B[N], C[N];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    rep(i, N){
        rep(j, N){
            rep(k, N){
                if(A[i] < B[j] && B[j] < C[k] && A[i] < C[k])
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}