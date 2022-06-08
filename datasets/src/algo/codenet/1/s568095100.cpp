#include <cstdio>

int main()
{
    int matrix[3][3];

    for(int i = 0; i <3; i++)
        for(int j = 0; j <3; j++)
            scanf("%d", &matrix[i][j]);

    int A[3];
    int B[3];

    A[0] = 0;
    B[0] = matrix[0][0] - A[0];
    B[1] = matrix[0][1] - A[0];
    B[2] = matrix[0][2] - A[0];
    A[1] = matrix[1][0] - B[0];
    A[2] = matrix[2][0] - B[0];

    int flag = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(A[i] + B[j] != matrix[i][j])
                flag =0;
    if(flag==1)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}