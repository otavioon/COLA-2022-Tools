#include<stdio.h>
#include<stdlib.h>

int main(void){
    int a[10000];
    int n,min,max,sum=0;
    char str[1000000000000];
    char tmp[12];
    int i,j,k=0,l=0,m;
    
    scanf("%d",&n);
    scanf("%s",str);
    
    for(j=0;str[j]!='\0';j++){
        if(str[j]!=' '){
            tmp[k]=str[i];
            k++;
        }else if(str[j]==' '){
            tmp[k]='\0';
            k=0;
            for(m=0;m<12;m++){
                tmp[m]='\0';
            }
            a[l]=atoi(tmp);
            l++;
        }
    }
    
    
    for(i=0;i<n;i++){
        sum+=a[i];
        if(i==0){
            min=a[i];
            max=a[i];
        }else if(a[i]<min){
            min=a[i];
        }else if(a[i]>max){
            max=a[i];
        }
    }
    
    printf("%d %d %d\n",min,max,sum);
    return 0;
}