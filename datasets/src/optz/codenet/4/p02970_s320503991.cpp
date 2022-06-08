#include <bits/stdc++.h>
using namespace std;
int main() {
    double n,d; cin>>n>>d;
    d=2*d+1;
    d=n/d;
    if(floor(d)==ceil(d)) d=d;
    else d=d+1;
    cout<<(int)d<<"\n";
}