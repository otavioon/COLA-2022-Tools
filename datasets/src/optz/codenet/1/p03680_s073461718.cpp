#include <bits/stdc++.h>
using namespace std;
int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    int ans = 0;
    int count  = 0;
    int j = 1;
    for(int i = 0;i < 100000;i++){
        count++;
        if(j > N)
        break;
        if(a[j - 1] == 2){
             ans = 1;
             break;
         }
         j = a[j - 1];
    }
    if(ans == 1){
        cout << count <<endl;
    }else{
        cout << dec << -1 << endl;
    }
}