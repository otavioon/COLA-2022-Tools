#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long int ll;

int main(){
    int c[3][3];
    int N = 0;
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
            N += c[i][j];
        }
    }
    if(N % 3 != 0){
        cout << "No";
        return 0;
    }else{
        N /= 3;
    }
    int a[3], b[3];
    for(a[0] = 0;a[0] <= N;++a[0]){
        for(a[1] = 0;a[1] <= N - a[0];++a[1]){
            for(a[2] = 0; a[2] <= N - a[1] - a[0];++a[2])
                for(b[0] = 0;b[0] <= N - a[0] - a[1] - a[2];++b[0]){
                    for(b[1] = 0;b[1] <= N - b[0] - a[0] - a[1] - a[2];++b[1]){
                        for(b[2] = 0;b[2] <= N - b[0] - b[1] - a[0] - a[1] - a[2];++b[2]){
                            bool flg = true;
                            rep(m, 3)
                                rep(u, 3)
                                    if(c[m][u] != b[m] + a[u])flg = false;
                            if(flg){
                                cout << "Yes";return 0;
                            }
                        }
                        //cout << b[2] << endl;
                    }
                }
            }
        }
    cout << "No";
}
