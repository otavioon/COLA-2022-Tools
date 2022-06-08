#include <bits/stdc++.h>

using namespace std;

int N, D;
int main(){
    
    cin >> N >> D;
    
    int ans = 1;
    int tree = 1;
    
    for (int i = 1; i <= N; i++) {
        if (tree == i - D) {
            tree = i + D + 1;
            i = tree;
            if (i <= N) {
                ans += 1;
            }
            
        }
        
    }
    cout << ans << endl;
    
}
