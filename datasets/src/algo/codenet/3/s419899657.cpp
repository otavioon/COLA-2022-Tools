#include <stdio.h>
int main(void)
{
	int n,a[10001],b[10001],c[10001],i,j,k,tmp,z=0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}for(i=0; i<n; i++){
		scanf("%d",&b[i]);
	}for(i=0; i<n; i++){
		scanf("%d",&c[i]);
	}
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i]<a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(b[i]<b[j]){
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(c[i]<c[j]){
				tmp=c[i];
				c[i]=c[j];
				c[j]=tmp;
			}
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(a[i]>=b[j]){
				break;
			}
			for(k=0; k<n; k++){
				if(b[j]<c[k]){
					z=z+1;
				}
			}
		}
	}
	printf("%d\n",z);
	return 0;
}