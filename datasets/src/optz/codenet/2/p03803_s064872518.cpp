/*|In The Name of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

long long n;

int a , b;
map < int , int > cnt;

int main(){
    cin >> a >> b;
    cnt[2] = 1;
    cnt[3] = 2;
    cnt[4] = 3;
    cnt[5] = 4;
    cnt[6] = 5;
    cnt[7] = 6;
    cnt[8] = 7;
    cnt[9] = 8;
    cnt[10] = 9;
    cnt[11] = 10;
    cnt[12] = 11;
    cnt[13] = 12;
    cnt[1] = 13;
    if(cnt[a] > cnt[b]){
        puts("Alice");
    } else if(cnt[a] < cnt[b]) {
        puts("Bob");
    } else {
        puts("Draw");
    }
}
