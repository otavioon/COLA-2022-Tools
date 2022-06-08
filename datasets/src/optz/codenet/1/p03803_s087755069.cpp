#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    int a=1000000000;
    int b=0;
    for(int i=1;i<=a;i++)b++;
    int alice,bob;cin>>alice>>bob;
    if(alice==1)alice+=100;if(bob==1)bob+=100;
    if(alice==bob)printf("Draw");
    else if(alice<bob)printf("Bob");
    else printf("Alice");
    
    return 0;
}
