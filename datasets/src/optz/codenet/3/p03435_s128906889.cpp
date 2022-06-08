#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> C(3, vector<int>(3));
vector<vector<int>> D(3, vector<int>(3));
vector<vector<int>> E(3, vector<int>(3));

bool check(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(D[i][j]!=D[(i+1)%3][j]) return false;
            if(E[i][j]!=E[i][(j+1)%3]) return false;
        }
    }
    return true;
}


int main() {

    for(vector<int> &v:C)
        for(int &c:v) cin >> c;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            D[i][j] = C[i][j] - C[i][(j+1)%3];
            E[i][j] = C[i][j] - C[(i+1)%3][j];
        }
    }
    
    if(check()) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
