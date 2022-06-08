#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num[10];

int getPrice(int key) {
    int price = 0, dum;
    int p[4] = {1000, 100, 10 ,1};
    int d[4];
    bool c;

    for(int i=key; i<10000; i++){
        d[0] = i/1000;
        dum = i%1000;
        d[1] = dum/100;
        dum = dum%100;
        d[2] = dum/10;
        dum = dum%10;
        d[3] = dum;

        c=true;
        for(int l=0; l<4; l++){
            if(num[d[l]] == -1){
                c = false;
            }
        }

        if(c == true){
            return i;
        }
    }
}

int main() {
    int n, k, l;

    for (int i = 0; i < 10; i++) {
        num[i] = 0;
    }

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> l;
        num[l] = -1;
    }

    cout << getPrice(n) << endl;

    return 0;
}







