#include<stdio.h>

int main(void){
    // c: 入力
    // flag: Y/Nの判定
    int c[3][3], flag = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &c[i][j]);
        }
    }

    // ex) c11 - c12 = (a1 + b1) - (a2 + b1) = a1 - a2
    //     c21 - c22 = (a1 + b2) - (a2 + b2) = a1 - a1
    // このような2値が等しくなるかを確認する
    // 4回のチェックで全体を確認し終える
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if((c[i][j] - c[i][j + 1]) != (c[i + 1][j] - c[i + 1][j + 1])){
                    flag = 0;
            }
        }
    }

    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}