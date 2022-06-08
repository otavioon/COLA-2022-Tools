#include<cstdio>

int main(){
    int a[3], b[3], c[3][3];
    for(int i = 0; i < 3; i++){
        scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
    }
    bool ans = true;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(!(c[i][j] + c[i+1][j+1] == c[i][j+1] + c[i+1][j]))
                ans = false;
        }
    }
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}
