#include <bits/stdc++.h>

using namespace std;
int n, x, a[105], sum;

int t(int i, int j){
    if(j < i){
        return j;
    }
    if(i <= j){
        return i;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> x;
        a[i]=x;
    }
    for(int i = 0; i < n; i++){
        sum+=t(a[i], a[i+1]);
    }
    sum+=a[n-2];
    sum+=a[0];
    cout << sum;
    return 0;
}
