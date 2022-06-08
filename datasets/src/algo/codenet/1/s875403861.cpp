#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int in0, in1, in2, sa10, sa20;
    int f = 0;
    rep(i, 3){
        cin >> in0 >> in1 >> in2;
        if(i != 0){
            if(sa10 != in1 - in0 || sa20 != in2 - in0) f = 1;
        }
        sa10 = in1 - in0;
        sa20 = in2 - in0;
    }
    if(f == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}