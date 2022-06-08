/**
 * @author: Jun
 * @date  : 03-17-2019
 **/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define el '\n'
#define MOD 1000000007

int n,k;
set<int> filt;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int g;
        cin >> g;
        filt.insert(g);
    }

    for(int i=n;i<=10000000;i++){
        bool can=true;
        int q = i;
        while(q!=0){
            if(filt.count(q%10)==1){
                can=false;
                break;
            }
            q /= 10;
        }
        if(can){
            cout << i << el;
            break;
        }
    }
    return 0;
}