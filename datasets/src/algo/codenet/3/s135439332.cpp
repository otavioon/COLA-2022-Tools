#include <bits/stdc++.h>
using namespace std;

long long int a[100000],b[100001],c[100001];

int main() {

    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        scanf(" %lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %lld",&b[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %lld",&c[i]);
    }

    b[n] = 2000000000;
    c[n] = 2000000000;

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    int ai=0,bi=0,ci=0;

    long long int ans = 0;

    for(int i=0; i<n; i++){

        while(a[ai] >= b[bi]){
            bi++;
        }

        if(bi == n){
            break;
        }

        while (b[bi] >= c[ci]) {
            ci++;
        }

        if (ci == n) {
            break;
        }

        int copybi = bi,copyci = ci;

        for(int j=copybi; j<n; j++) {

            while (b[copybi] >= c[copyci]) {
                copyci++;
            }

            if (copyci == n) {
                break;
            }

            ans += (n-copyci);

            copybi++;

        }

        ai++;

    }

    cout << ans << endl;



    return 0;
}