#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<numeric>

using namespace std;

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b){
    return (a/gcd(a,b))*b;
}

int main() {
    int A,B;
    cin>>A>>B;
    if(A!=1||B!=1){
    if(A>B)cout<<"Alice"<<endl;
    if(A<B)cout<<"Bob"<<endl;
    if(A==B)cout<<"Draw"<<endl;
    }
    else{
        if(A==1&&B!=1)cout<<"Alice"<<endl;
        if(B==1&&A!=1)cout<<"Bob"<<endl;
        if(A==B)cout<<"Draw"<<endl;
    }
    return 0;
}