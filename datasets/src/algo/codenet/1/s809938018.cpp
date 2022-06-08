#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() { 
    int score, cnt =0;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
           cin >> score;
            cnt += score;
        }
    }
    if(cnt%3==0)cout << "Yes" << endl;
    else if(cnt%3!=0) cout << "No" << endl;

    return 0;
}