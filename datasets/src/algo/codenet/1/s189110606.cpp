#include<stdio.h>
#include<algorithm>
using namespace std;
int a[3][3];
int main(){
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<2;i++){
        int t=a[i][0]-a[i+1][0];
        for(int j=1;j<3;j++) if(a[i][j]-a[i+1][j]!=t){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
