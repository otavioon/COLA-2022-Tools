#include <stdio.h>
#include <stdint.h>

int main(){

	char s[101]={0};
	int k=0;
	uint8_t i=0;
  	int count=0;
  	bool judge=0;
  
	scanf("%s",s);
	scanf("%d",&k);

	while(1){
    	if(s[i]=='\0'){
          	if(s[i-1]==s[0]){
              	if(s[0]==s[1]){
                }else{
                	if(s[i-1]==s[i-2]){
                    
                    }else{
                    	count++;
                    }
                }
            	//count++;
            }
        	break;
        }
      
      	if(s[i]==s[i+1]){
          	if(judge==1){
            	judge=0;
            }else{
              judge=1;
              count++;
              //printf("%d:%c\n",i,s[i]);
            }
        }else{
        	judge=0;
        }
      	
      	i++;  	
    }
	unsigned long long int ans = (unsigned long long int)count *(unsigned long long int)k;
	//printf("%d,%d\t",count,k);
	printf("%ld",ans);
  
	return 0;

}