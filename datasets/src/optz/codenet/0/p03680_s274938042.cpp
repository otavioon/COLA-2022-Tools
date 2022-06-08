#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int cnt = 1;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int key = a[0];

    for(int i = 0; i < n; i++){
        if(a[key-1] == 2){
            cout << ++cnt << endl;
            return 0;
        }else{
            key = a[key-1];
            cnt++;
        }
    }
    cout << -1 << endl;
}