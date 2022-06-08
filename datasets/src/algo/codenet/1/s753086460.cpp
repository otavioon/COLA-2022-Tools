#include <bits/stdc++.h>
using namespace std;

int main() {
int arr[9];
bool flag=false;
for(int i =0 ; i< 9 ;++i)
scanf("%d",&arr[i]);
int cmp1=arr[3]-arr[0],
cmp2 = arr[6]-arr[0];
if (arr[4]-arr[1]==cmp1 && arr[5]-arr[2]==cmp1)
	if (arr[7]-arr[1]==cmp2 && arr[8]-arr[2] == cmp2)
		flag=true;

if (flag)
printf("Yes\n");
else
printf("No\n");

	return 0;
}