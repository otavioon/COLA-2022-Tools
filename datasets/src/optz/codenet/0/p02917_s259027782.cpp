#include<stdio.h>
#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;

    int b[100];
    int a = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(i == 0){
            a += b[i];
        } else {
            if(b[i-1] < b[i]) {
                a += b[i-1];
            } else {
                a += b[i];
            }
        }
    }

    cout << a << endl;

}
