#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

void haiten(int p, int x, vector<vector<int>> seten, vector<int> &ans){
    int i=0;
    //cout << "p" << p << endl;
    ans[p]+=x;
    while(seten[p][i]!=0){
        //cout << p << ":" << x << endl;
        //cout << ":" << ans[3] << endl;
        //cout << seten[p][i] << endl;
        haiten(seten[p][i], x, seten, ans);
        i++;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> seten(n+1, vector<int>(n, 0));
    vector<int> cnt(n+1, 0);
    vector<int> ans(n+1, 0);

    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        seten[a][cnt[a]] = b;
        cnt[a]++;
    }

    /*
    cout << "a" << seten[1][0] << endl; 
    cout << "a" << seten[2][0] << endl; 
    cout << "a" << seten[2][1] << endl;
    */
    //ある接点ｘにはcnt[x]この子があり，
    //その子の接点をsetenで表す

    for(int i=0;i<q;i++){
        int p, x;
        cin >> p >> x;
        haiten(p, x, seten, ans);
    }

    rep(i, n) cout << ans[i+1] << endl;

    return 0;
}