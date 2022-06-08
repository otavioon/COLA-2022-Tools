#include <stdio.h>

int main(){

    int i,j,x[10000],y[10000];
     i=1;
    
    while(1){
	  
	  scanf("%d",&x[i]);
	  scanf("%d",&y[i]);
      if ((x[i]==0)&&(y[i]==0)) break;
      if (x[i]>y[i]) {
		  j=x[i];
		  x[i]=y[i];
		  y[i]=j;
	  }
      ++i;
    }	  
     
       for (j=1;j<i;++j){
	 	printf("%d %d\n",x[j],y[j]);
	  }
		
	return 0;
}