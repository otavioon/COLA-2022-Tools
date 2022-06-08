#include<cstdio>

using namespace std;

int main(){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);

    }
    if (c[1][0] - c[0][0] == c[1][1] - c[0][1] && c[1][1] - c[0][1] == c[1][2] - c[0][2] && c[2][0] - c[0][0] == c[2][1] - c[0][1] && c[2][1] - c[0][1] == c[2][2] - c[0][2]){
        puts("Yes");
    }else{
        puts("No");
    }
}