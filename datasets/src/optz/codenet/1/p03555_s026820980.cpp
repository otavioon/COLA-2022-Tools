#include <bits/stdc++.h>

using namespace std;

int main(void){
    vector<vector<char>>mat(2,vector<char>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat.at(i).at(j);
        }
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.at(0).size();j++){
            if( mat.at(i).at(j) != mat.at(1-i).at(2-j) ){
                goto OUT;
            }
        }
    }
    cout<<"YES"<<endl;
    OUT:
        cout<<"NO"<<endl;
    return 0;
}
