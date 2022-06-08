#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int arr[110];
bool f(int a, int b){
return a>b ;}
int main(){
    int i;
    for(i=1;i<=9;i++){
        scanf("%d",&arr[i]);
    }
    if(arr[1]+arr[5]==arr[2]+arr[4]&&arr[1]+arr[9]==arr[3]+arr[7]&&arr[9]+arr[5]==arr[6]+arr[8]){
        printf("Yes");
    }
else printf("No");
}
