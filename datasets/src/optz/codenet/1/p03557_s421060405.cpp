#include <iostream>
#include <math.h>
using namespace std;

long long n, eye, ans = 0;
long long uber[100001], mitte[100001], unter[100001];

int main() {
    cin>>n;
    for(int i = 0; i<= 100000; i++) {
        uber[i] = 0;
        mitte[i] = 0;
        unter[i] = 0;
    }
    for(int i = 1; i<= n; i++) {
        cin>>eye;
        uber[eye]++;
    }
    for(int i = 1; i<= n; i++) {
        cin>>eye;
        mitte[eye]++;
    }
    for(int i = 1; i<= n; i++) {
        cin>>eye;
        unter[eye]++;
    }
    for(int i = 2; i<= 100000; i++) 
        uber[i] += uber[i-1];
    for(int i = 1; i <= 100000; i++)
        mitte[i] *= uber[i-1];
    for(int i = 2; i <= 100000; i++)
        mitte[i] += mitte[i-1];
    for(int i = 1; i <= 100000; i++)
        unter[i] *= mitte[i-1];
    for(int i = 1; i <= 100000; i++)
        ans += unter[i];
    cout<<ans;
}