#include<stdio.h>


int main(){
    int a[3002];
    int b[3002];
    int j,i;
    i = 0;
    while(1){
        int temp1,temp2;
        scanf("%d%d",&temp1,&temp2);
        if(temp1 >= temp2){
            a[i] = temp2;
            b[i] = temp1;
            
        }
        else{
            a[i] = temp1;
            b[i] = temp2;
        }
        if(a[i]==0){
          if(b[i]==0)
             break;
        }
        i++;    
    }
    for(j=0;j<i;j++){
        printf("%d %d\n",a[j],b[j]);
    }
    return 0;
    
}
