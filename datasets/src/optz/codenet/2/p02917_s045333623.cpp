#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> B;
    for(int i=0;i<n-1;++i){
        int b; cin >> b;
        B.push_back(b);
    }

    int a[n];
    fill(a, a+n, 10e8);
    for(int i=0;i<n-1;++i){
        a[i] = min(a[i], B[i]);
        a[i+1] = min(a[i+1], B[i]);
    }
    cout << accumulate(a, a+n, 0) << endl;

}
