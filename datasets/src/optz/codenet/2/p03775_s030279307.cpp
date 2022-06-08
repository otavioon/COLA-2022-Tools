#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
double PI=acos(-1);

LL n;

int f(LL s)
{
    int i=0;
    while(s>=1){
        i++;
        s/=10;
    }
    return i;
}

int main()
{
    while(cin>>n){

        int s=sqrt(n*1.0);
        while(s>=1){
            if(n%s==0){
                break;
            }
            s--;
        }
        cout<<f(n/s)<<endl;

    }
    return 0;
}
