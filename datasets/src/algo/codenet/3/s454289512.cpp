#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define INF ((1<<31)-1)

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

    sort(b, b+n);
    sort(c, c+n);
    long cnt = 0;
    for (int i = 0; i < n; i++){
        int searchNo1 = a[i];
        int left = -1, right = n;     //  こうすることで常にleft, right を確認する意味はなくなり、while文の条件が活きる
        int mid;
        while ( right-left > 1){
            mid = (left + right) / 2;
            if (b[mid]>searchNo1){
                right = mid;
            }
            else{
                left = mid;
            }
        }

        mid = left;
        for (int j = mid+1; j < n; j++){
            int searchNo2 = b[j];
            left = -1, right = n;
            while ( right-left > 1){
                mid = (left + right) / 2;
                if (c[mid]>searchNo2){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            cnt += n - right;
        }
    }

    cout << cnt << endl;

    return 0;
}
