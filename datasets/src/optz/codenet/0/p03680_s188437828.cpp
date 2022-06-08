#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int k = 0;
    int count = 0;
    do{
        k = a[k];
        b[k]++;
        if(b[k] == 2) k = 0;
        count++;
    }while(k != 0 && k != 1);
    if(k == 1) cout << count;
    else cout << -1;
}
