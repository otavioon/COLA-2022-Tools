#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char z[1000];
	int i,j=1,n,k,m=0,s[1000],l[1000];
	gets(z);
	n=strlen(z);
	for(i=0;i<n;i++){
		if(z[i]==' '){
			s[j]=i;
			j++;
		}
	}
	s[j]=n;
	s[0]=-1;
	for(k=0;k<j;k++){
		if(s[k+1]-s[k]-1!=0){
		l[m]=s[k+1]-s[k]-1;
		m++;
		}
	}
	m--;
	for(i=0;i<=m;i++){
		if(i==0){
	printf("%d",l[i]);
		}else{
			printf(",%d",l[i]);
		}
	}
	printf("\n");

	return 0;
}
