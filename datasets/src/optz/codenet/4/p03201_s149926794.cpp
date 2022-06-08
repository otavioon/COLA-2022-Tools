#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    sort(A, A+N, greater<ll>());
    vector<pair<ll, int>> B;
    int row = 0;
    rep(i, N){
        if(i == 0){
            row++;
        }
        else if(i == N-1){
            if(A[i] != A[i-1]){
                B.push_back(make_pair(A[i-1], row));
                B.push_back(make_pair(A[i], 1));
            }
            else{
                row++;
                B.push_back(make_pair(A[i], row));
            }
        }
        else{
            if(A[i] != A[i-1]){
                B.push_back(make_pair(A[i-1], row));
                row = 1;
            }
            else row++;
        }
    }
    int idx = 0, cnt = 0;
    ll pow2[32] = {1};
    for(int i = 1; i < 32; i++){
        pow2[i] = pow2[i-1]*2;
    }

    while(idx < B.size()){
        ll num = B[idx].first;
        bool found = false;
        int beki = (int) log2(num);
        ll aim = pow2[beki+1] - num;
        cout << num << " " << aim << endl;
        //aimをBの中からにぶたん、あればfound = true
        int ng = -1, ok = B.size();
        int m = (ng+ok)/2;
        while(abs(ng-ok) > 1){
            if(B[m].first > aim) ng = m;
            else ok = m;
            m = (ng+ok)/2;
        }
        if(B[ok].first == aim && B[ok].second > 0) found = true;
        if(aim == num && B[ok].second <= 1) found = false;

        if(found){
            cnt++;
            B[idx].second -= 1;
            B[ok].second -= 1;
            if(B[idx].second == 0) idx++;
        }
        else idx++;
    }
    cout << cnt << endl;
    return 0;
}