#include <bits/stdc++.h>
using namespace std;

#define N 100000

int n, a[N], b[N], c[N];

int main(void)
{
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

    sort(a, a+n);
    sort(b, b+n); // やらなくていい
    sort(c, c+n);

    // b を基準にして、あてはまる a, c の数を算出する
    long cnt = 0;
    int bTmp, left, right, mid, nATmp, nCTmp;
    for (int i = 0; i < n; i++){
        bTmp = b[i];
        left = -1, right = n;     //  こうすることで常にleft, right を確認する意味はなくなり、while文の条件が活きる
        while ( right-left > 1){
            mid = (left + right) / 2;
            if (a[mid]>=bTmp){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        nATmp = right;

        left = -1, right = n;
        while ( right-left > 1){
            mid = (left + right) / 2;
            if (c[mid]>bTmp){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        nCTmp = n - right;
        cnt += (long) nATmp * nCTmp;
    }

    cout << cnt << endl;

    return 0;
}

