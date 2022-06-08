#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int count[n];
    long re=0;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if(b[j]<c[i]){
                count[j]=n-i;
                break;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if(a[k]<b[i])re+=count[i];
        }
    }
    cout<<re<<endl;
    return 0;
}