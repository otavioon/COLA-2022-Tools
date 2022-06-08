#include<iostream>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>

#define ll long long

using namespace std;

const ll INF = 1000000000;
int N;
vector<vector<ll>> S;
int b_place=0;
int c_place=0;
ll cnt=0;
vector<int> b_cnt;

int main()
{
    cin >> N;
    S.resize(3);
    b_cnt.resize(N);
    for (int i=0; i<3; i++) {
        S[i].resize(N+1);
        for (int j=0; j<N; j++) {
            cin >> S[i][j];
        }
        sort(S[i].begin(), S[i].end()-1);
       S[i][N] = INF;
    }
    
    for (int i=0; i<N; i++) {
        while (S[1][i] >= S[2][c_place]) {
            c_place++;
        }
        b_cnt[i] = N - c_place;
    }

    for (int i=0; i<N; i++) {
        while (S[0][i] >= S[1][b_place]) {
            b_place++;
        }
        for (int j=b_place; j<N; j++) {
        cnt += b_cnt[j];
        }
    }
    
    cout << cnt << endl;
    return 0;
}