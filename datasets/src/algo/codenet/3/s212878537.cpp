#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

using namespace std;

int counter = 0;

int N;
int a[100001];
int b[100001];
int c[100001];
int bmemo[100001];


int main(){
    ios::sync_with_stdio(false);
    
    cin >> N;
    rep(i, N)
//        cin >> a[i];
        scanf("%d", &a[i]);
    
    rep(i, N)
//        cin >> b[i];
        scanf("%d", &b[i]);

    rep(i, N)    
//        cin >> c[i];
        scanf("%d", &c[i]);
    
    asort(a, N);
    asort(b, N);
    asort(c, N);
    memset(bmemo, -1, sizeof(b));
    int ans = 0;

    for(int i = N - 1;i >= 0;--i){
        for(int j = N - 1;j>= 0; --j){
            if(b[j] <= a[i]){
                break;
            }
            if(bmemo[j] == -1){
                for(int k = N - 1;k >= 0;--k){
                    //a[i], b[j], c[k]
                    if(c[k] <= b[j]){
                        bmemo[j] = counter;
                        ans += counter;
                        counter = 0;
                        break;     
                    }
                    counter++;
                }
            }else{
                ans += bmemo[j];
            }
            
        }
    }

    ans += counter;
    /*
    for(int i = N - 1;i >= 0;--i){
        for(int j = N - 1;j>= 0; --j){
            if(b[j] <= a[i])
                break;
            for(int k = N - 1;k >= 0;--k){
                //a[i], b[j], c[k]
                if(c[k] <= b[j])
                    break;
                counter++;
            }
        }
    }
    */



    cout << ans << endl;

    return 0;
}