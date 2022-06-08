#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <queue>
#include <functional>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

int n;
int a[100005];
int b[100005];
int c[100005];

int upper_bound(int k){
    int lb = 0, ub = n;

    while (ub - lb > 1){
        int mid = (lb + ub) / 2;
        if (a[mid] < b[k]){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    return lb;
}

int lower_bound(int k){
    int lb = -1, ub = n - 1;

    while (ub - lb > 1){
        int mid = (lb + ub) / 2;
        if (c[mid] > b[k]){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }
    return ub;
}


int main(void){

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    ll ans = 0;
    for (int k = 0; k < n; k++){
        int sa = upper_bound(k);
        int sc = lower_bound(k);
        ans += (sa + 1)*(n - sc);
    }

    cout << ans << endl;

    

}