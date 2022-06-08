#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int c[9];
int main(void){
    for(int i=0;i<9;i++)scanf("%d",c+i);
    if(c[0]+c[4]==c[1]+c[3]&&c[1]+c[5]==c[2]+c[4]&&c[3]+c[7]==c[4]+c[6]&&c[4]+c[8]==c[5]+c[7])printf("Yes\n");
    else printf("No\n");
    
}
