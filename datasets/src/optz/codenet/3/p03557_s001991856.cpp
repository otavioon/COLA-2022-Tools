#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int n,int x,int array[]){
    int s,t;
    s = 0,t = n;
    int res = -1;
    while(t - s >= 1){
        int mid = s + (t - s)/2;
        if(array[mid] < x){
            res = mid;
            s = mid + 1;
        } else {
            t = mid;
        }
    }
    return res;
}

int fetchUpperBound(int n,int x,int array[]) {
    int s = 0,t = n;
    int res = -1;
    while(t - s >= 1){
        int mid = s + (t - s)/2;
        if(array[mid] <= x){
            res = mid;
            s = mid+1;
        } else {
            t = mid;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    int res = 0;
    int ans1, ans2 = 0;
    int cnt;
    for(int i = 0;i < n;i++ ){
        int lower = binarySearch(n, b[i], a) + 1;
        int upper = fetchUpperBound(n, b[i], c) + 1;
        res += lower*(n - upper);
    }
    cout << res << endl;

    return 0;
}