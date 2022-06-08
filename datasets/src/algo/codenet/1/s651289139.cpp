#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ar[5][5];

int main()
{

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&ar[i][j]);
        }
    }
    int a1,a2,a3,b1,b2,b3;
    a1 = 0;
    b1 = ar[1][1];
    b2 = ar[1][2];
    b3 = ar[1][3];
    a2 = b1 - ar[2][1];
    a3 = b1 - ar[3][1];
    if(a1+b1!=ar[1][1]||a1+b2!=ar[1][2]||a1+b3!=ar[1][3]||a2+b1!=ar[2][1]||a2+b2!=ar[2][2]||a2+b3!=ar[2][3]||a3+b1!=ar[3][1]||a3+b2!=ar[3][2]||a3+b3!=ar[3][3])
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
