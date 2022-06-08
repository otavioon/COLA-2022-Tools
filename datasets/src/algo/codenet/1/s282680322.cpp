#include<bits/stdc++.h>
using namespace std;
/*
c1,1 c1,2 c1,3
c2,1 c2,2 c2,3
c3,1 c3,2 c3,3
*/
/*

    a1+b1=c11
    a2+b2=c22
    a3+b3=c33
a1+b2=c12
a1+b3=c13
    a2+b1=c21
    a2+b3=c23
a3+b1=c31
a3+b2=c32

*/

int main()
{
            /*  c12 +c21 = c11+c22
                c23+c32 = c22 +c33
                c13 +c31= c11+c33*/
    int c[4][4];
    for(int i=1; i <4 ; ++i)
        for(int j=1 ; j<4 ; ++j){
            cin>>c[i][j];
        }
    puts((c[1][2]+c[2][1]== c[1][1]+c[2][2] &&
       c[2][3] + c[3][2] == c[2][2] + c[3][3] &&
        c[1][3] + c[3][1] == c[1][1] +c[3][3]
       )?"Yes" : "No");

}
