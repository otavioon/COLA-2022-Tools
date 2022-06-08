// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
   // int kazu[1005];
    int ans = 0;
    cin >> n;
   // int ruiseki[1005];
  //  vector<int>a;
    //for (int i = 0; i < n; i++) {
    //    int l;
    //    cin >> l;
    //    a.push_back(l);
    //    
    //}
    //sort(a.begin(), a.end());

    //for (int i = 0; i < a.size() - 2; i++) {
    //    for (int j = i+1; j < a.size() - 1; j++) {
    //        for (int k = j+1; k < a.size(); k++) {
    //            if (a[i] + a[j] > a[k]) {
    //                ans++;
    //            }
    //            else {
    //                break;
    //            }
    //        }
    //    }
    //}
    vector<int>L(n);
    for (int i = 0; i < n; i++)cin >> L[i];

    for (int b = 0; b < n; b++) {
        for (int a = 0; a < b; a++) {
            int ab = L[a] + L[b];
            int r = lower_bound(L.begin(), L.end(), ab) - L.begin();
            int l = b + 1;
            ans += max(0, r - l);
        }
    }

    cout << ans << endl;
}

