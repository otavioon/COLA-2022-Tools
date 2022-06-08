#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int grid[3][3];
int sumCom , digonal1 , diagonal2;
int main() {

    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            cin >> grid[i][j];
            sumCom += grid[i][j];
        }
    }

    digonal1 = grid[0][0] + grid[1][1] + grid[2][2];
    diagonal2 = grid[0][2] + grid[1][1] + grid[2][0];

    if(sumCom == digonal1*3 && sumCom == diagonal2*3)
        puts("Yes");
    else
        puts("No");


	return 0;
}
