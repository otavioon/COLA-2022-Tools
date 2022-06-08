#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int k = 0;
    int count = 0;
    do{
        if(k != 1 && k == a[k]){
            k = 1;
            break;
        }
        k = a[k];
        count++;
    }while(k != 0 && k != 1);
    if(k == 1) cout << count;
    else cout << -1;
}

