#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)


int dfs(int sum, int N, vector<int> &oknum){
    if (sum>=N){
        //cout << sum << endl;
        return sum;
    }

    int minsum = 1<<16;
    for(int x: oknum){
        int nv =sum*10 + x;
        if (nv==0) continue;
        int s = dfs(nv, N, oknum);
        minsum = min(s, minsum);
    }
    return minsum;
}

int main()
{
    int N, K;
    cin >> N>>K;
    vector<int> ngnum(10);
    REP(i, K){
        int a;
        cin >> a;
        ngnum[a] = 1;
    }
    vector<int> oknum;
    REP(i, 10){
        if (ngnum[i] == 0){
            oknum.push_back(i);
            //cout << i << " ";
        }
    }
    cout << endl;
    int minsum = dfs(0,N, oknum);
    cout << minsum << endl;
   return 0;
}