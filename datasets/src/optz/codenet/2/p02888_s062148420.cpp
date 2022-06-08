#include <iostream>
#include <vector>
using namespace std;
int memo[2010][2010];
int l[2010];
int n;
int dfs(int phase, int first = -1, int second = -1){
    int count = 0;
    switch(phase){
    case 0:
        for(int i = 0; i < n; i++) count += dfs(phase+1, i);
        break;
    case 1:
        for(int i = first+1; i < n; i++) count += dfs(phase+1, first, i);
        break;
    case 2:
        for(int i = second+1; i < n; i++){
            if(!memo[first][second]) memo[first][second] = l[first]+l[second];
            if(!memo[first][i]) memo[first][i] = l[first]+l[i];
            if(!memo[second][i]) memo[second][i] = l[second]+l[i];
            
            if(l[first] < memo[second][i] && l[second] < memo[first][i] && l[i] < memo[first][second]) count++;
        }
    }
    return count;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i];
    int count;
    count = dfs(0);
    
    cout << count << endl;
    return 0;
}
    