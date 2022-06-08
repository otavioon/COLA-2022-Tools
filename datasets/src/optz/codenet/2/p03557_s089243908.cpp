#include <bits/stdc++.h>
using namespace std;

int Cumulative_sum[100000001][2];

int main() {

    int n;

    cin >> n;

    map<int,int> a,b,c;

    for(int i=0; i<n; i++){
        int ai;
        cin >> ai;
        a[ai]++;
    }

    for(int i=0; i<n; i++){
        int bi;
        cin >> bi;
        b[bi]++;
    }

    for(int i=0; i<n; i++){
        int ci;
        cin >> ci;
        c[ci]++;
    }

    for(int i=1; i<100000001; i++){
        Cumulative_sum[i][0] += Cumulative_sum[i-1][0] + a[i];
    }

    for(map<int,int>::iterator itr = b.begin(); itr != b.end(); itr++){
        Cumulative_sum[itr->first][1] = itr->second * Cumulative_sum[itr->first][0];
    }

    for(int i=1; i<100000001; i++){
        Cumulative_sum[i][1] += Cumulative_sum[i-1][1] + a[i];
    }

    for(map<int,int>::iterator itr = c.begin(); itr != c.end(); itr++){
        Cumulative_sum[itr->first][2] = itr->second * Cumulative_sum[itr->first][1];
    }

    for(int i=1; i<100000001; i++){
        Cumulative_sum[i][2] += Cumulative_sum[i-1][2] + a[i];
    }

    cout << Cumulative_sum[100000000][2] << endl;



    return 0;
}