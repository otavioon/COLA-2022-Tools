#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

#define rep(i, s) for (int i = 0; i < s; ++i)
#define all(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define VEC(a, n) vector<int>a(n)
#define PQ(a) priority_queue<int>a
#define PQmin(a) priority_queue< int, :vector<int>, greater<int> >a
#define PAIR pair<int, int>
/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int n,k;
vector<int>d(k);

int dfs(vector<int>&d, vector<bool>&vec, int n){
    int tmp=n;
    bool flag=false;
    while(tmp!=0){
        for(int i=0;i<10;i++){
            if(vec.at(i)){
                if(tmp%10==i)dfs(d, vec, n+1);
            }
        }
        tmp/=10;
    }
    cout<<n<<endl;
    exit(0);
}


int main() {
    cin>>n>>k;
    vector<bool>vec(10, false);
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        vec.at(x)=true;
    }
    dfs(d, vec, n);



    return 0;
}