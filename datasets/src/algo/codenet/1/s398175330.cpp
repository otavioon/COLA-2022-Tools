#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
int a[3][3];

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int p=a[0][1]-a[0][0];
    int q=a[0][2]-a[0][1];
    if(p!=a[1][1]-a[1][0] || p!=a[2][1]-a[2][0] || q!=a[1][2]-a[1][1] || q!=a[2][2]-a[2][1]){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}