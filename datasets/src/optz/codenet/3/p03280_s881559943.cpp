#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#define rep(i,n) for (int i = 0; (i) < (n); ++ (i))
#define int long long
using namespace std;
 
signed main(void){
    int n,mone = 0,mtwo = 0;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> aligns(n);
    rep(i,n) {
        cin >> aligns[i];
    }
    sort(aligns.begin(),aligns.end());
    if(aligns.size() == 2) {
        return aligns[1] - aligns[0];
    }
    rep(i,n) {
        mone += aligns[n-1-i] - aligns[i];
        mtwo += aligns[n-1-i] - aligns[i];
        if(n-1-i-i == 2) {
            mone += aligns[n-1] - aligns[i+1];
            mtwo += aligns[i+1] - aligns[0];
            break;
        } else if(n-1-i-i == 3) {
            mone += aligns[n-2-i] - aligns[i];
            mtwo += aligns[n-1-i] - aligns[i+1];
            mone += aligns[n-1] - aligns[i+1];
            mtwo += aligns[i+2] - aligns[0];
            break;
        } else {
            mone += aligns[n-2-i] - aligns[i];
            mtwo += aligns[n-1-i] - aligns[i+1]; 
        }
    }
    cout << max(mone,mtwo) << endl;
    return 0;
}