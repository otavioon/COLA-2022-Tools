#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int m=0,a[1000000],b[1000000],c[1000000],flg1[1000000],flg2[1000000],z[100000];
int main(void)
{
	int n,i,j,x,y,r;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
	    scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
	    scanf("%d",&c[i]);
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
/*	for(i=0;i<n;i++){
	    printf("%d\n",a[i]);
	}
	for(i=0;i<n;i++){
	    printf("%d\n",b[i]);
	}
	for(i=0;i<n;i++){
	    printf("%d\n",c[i]);
	}*/
	for(i=0;i<n;i++) flg1[i]=0;
	for(i=0;i<n;i++) flg2[i]=0;
	x=0;y=0;r=0;
	for(i=0;i<n;i++){
		if(a[i]<b[r]){
		    flg1[r]++;
		}
		else{
		    r++;
			i--;
		}
		if(n<=r) break;
	}
//	for(i=0;i<n;i++) printf("%d\n",flg1[i]);
	r=0;
	for(i=0;i<n;i++){
	    x+=flg1[i];
		flg1[i]=0;
	//	printf("%d %d %d\n",x,flg1[i],i);
		if(b[i]<c[r]){
			y+=(n-r)*x;
	//		printf("%d+=(%d-%d)*%d\n",y,n,r,x); 
		}
		else{
		    r++;
			i--;
		}
		if(n<=r) break;
	}
	printf("%d\n",y);
	return 0;
}