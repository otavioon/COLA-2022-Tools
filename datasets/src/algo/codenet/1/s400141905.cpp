#include<bits/stdc++.h>
using namespace std;

int A[5][5];

int main()
{
    for(int i = 0; i < 3; i++)for(int j = 0; j < 3; j++)scanf("%d",&A[i][j]);

    if(A[0][0] + A[1][1] + A[2][2] == A[0][2] + A[1][0] + A[2][1] && A[0][0] + A[1][1] + A[2][2] == A[0][1] + A[1][2] + A[2][0])printf("Yes\n");
    else printf("No\n");
    return 0;
}
