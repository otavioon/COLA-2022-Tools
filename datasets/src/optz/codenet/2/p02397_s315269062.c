#include<stdio.h>

int main()
{
	int a[3000],b[3000],i,j,x;
	
	for(i=0;i<3000;i++){
	scanf("%d %d",&a[i],&b[i]);
	if(a[i]==0&&b[i]==0){
		break;}
	else if(a[i]>b[i]){
		x=a[i];
		a[i]=b[i];
		b[i]=x;
	}}
	
	for(j=0;j<i;j++){
	printf("%d %d\n",a[j],b[j]);
	}

	return 0;
}