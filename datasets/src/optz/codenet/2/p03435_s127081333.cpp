#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    vector<vector<int>> inputs(3, vector<int>(3));
    int c_max = 0;
    rep(i, 3){
        rep(j, 3){
            cin >> inputs.at(i).at(j);
            c_max = max(c_max, inputs.at(i).at(j));
        }
    }
    vector<int> As(3);
    vector<int> Bs(3);
    rep(a1, c_max*2+1){
        rep(i, inputs.size()){
            Bs.at(i) = inputs.at(0).at(i) - a1;
        }
        rep(i, inputs.at(0).size()){
            As.at(i) = inputs.at(i).at(0) - Bs.at(0);
        }
        bool ans = true;
        rep(i, inputs.size()){
            rep(j, inputs.at(i).size()){
                if(inputs.at(i).at(j) != As.at(i) + Bs.at(j)){
                    ans = false;
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}