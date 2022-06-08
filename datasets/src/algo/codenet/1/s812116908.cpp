#include <bits/stdc++.h>
using namespace std;

int main(){
    int C[9];
    for(int i=0;i<9;i++) cin >> C[i];

    //int a1 =0;
    if((C[3]-C[0]== C[4]-C[1])&&(C[4]-C[1]==C[5]-C[2])&&(C[6]-C[0]== C[7]-C[1])&&(C[7]-C[1]==C[8]-C[2])) cout << "Yes" << endl;
    else cout << "No" << endl;

}