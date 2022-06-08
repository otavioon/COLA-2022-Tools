#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b;
    int c1,c2,c3;
    cin >> c1 >> c2 >> c3;
    a = c2-c1;
    b = c3-c2;
    bool possible = true;
    for(int i=0; i<2; i++){
        int p,q,r;
        cin >> p >> q >> r;
        if(q-p != a || r-q != b){
            possible = false;
        }
    }
    if(possible){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}