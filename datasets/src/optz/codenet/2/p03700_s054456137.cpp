#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 1e5+10;
int a[MAXN], b[MAXN];
int n, x, y;

bool is_ok(int mid){
    memcpy(b, a, sizeof(a));
    for(int i=0; i<n; i++){
        b[i] -= mid * y;
    }
    for(int i=0; i<n; i++){
        if(b[i] > 0){
            int cnt = x - y;
            int cc = b[i]/cnt;
            mid -= cc;
            if(b[i] % cnt) mid -= 1;
            if(mid < 0) return false;
        }
    }
    return true;
}

int main(void){
    scanf("%d%d%d", &n, &x, &y);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int l=1, r=1e9;
    while(l < r){
        int mid = (l + r) >> 1;
        // cout << l << " " << r << " " << mid << " " << is_ok(mid) << " " << is_ok(mid-1) << endl;
        if(is_ok(mid) && !is_ok(mid-1)){
            printf("%d\n", mid);
            return 0;
        }else if(is_ok(mid)){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}