
#include <stdio.h>

int main() {

    int i,s,temp;
    i = s = 0;
    int x[10000],y[10000];

    while(1){
    	scanf("%d %d", &x[i], &y[i]);
    	if(x[i] > y[i]){
    		temp = x[i];
    	    x[i] = y[i];
    	    y[i] = temp;
    	}

    	i++;

    	if(x[i-1]==0 && y[i-1] == 0){
    		break;
    	}
    }


    for(s=0;s<i-1;s++){
    	printf("%d %d\n",x[s], y[s]);
    }

    return 0;
}