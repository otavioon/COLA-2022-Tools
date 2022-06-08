#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    long long num;
    long long cnt = 0;
    long long tmpCnt = 0;
    bool chk = true;

    cin >> str >> num;

    for (int i = 0; i < str.size() - 1; i++) {
        if (str.at(i) != str.at(i + 1)) chk = false;
    }

    if (chk == false) {
        for (int i = 0; i < str.size() - 1; i++) {
            if (str.at(i) == str.at(i + 1)) {
                tmpCnt = 0;
                for (int j = i; j < str.size() - 1; j++) {
                    i = j;
                    if (str.at(j) == str.at(j + 1)) tmpCnt++;
                    else break;
                }
                
                cnt += (tmpCnt+1) / 2;
            }
        }
    }

    if (chk == true) {
        cnt = str.size() * num / 2;
    } else if (str.at(0) == str.at(str.size() - 1)) {
        tmpCnt = 0;
        for (int i = 0; i < str.size() - 1; i++){
            if (str.at(i) == str.at(i + 1)) tmpCnt++;
            else break;
        }
        for (int i = str.size() - 1; i > 0; i--){
            if (str.at(i) == str.at(i - 1)) tmpCnt++;
            else break;
        }
        cout << cnt << endl;
        cnt *= num;
        if(tmpCnt % 2 == 0) cnt += num - 1;
    } else {
        cnt *= num;
    }

    cout << cnt;
    //
}
