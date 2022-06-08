#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

int N, K;
//map<int, int> record;
set<int> record;

int main() {
    scanf("%d%d", &N, &K);
    int num;
    for (int i = 0; i < K; i++) {
        cin >> num;
        record.insert(num);
    }
    for (int i = N;;i++) {
        int j = i;
        bool flag = true;
        while(0 < j) {
            int digit = j % 10;
            j /= 10;
            if(record.find(digit) != record.end())
                flag = false;
        }
        if(flag) {
            num = i;
            break;
        }
    }

    printf("%d\n", num);
    return 0;
}