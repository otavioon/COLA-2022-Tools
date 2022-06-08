#include <stdio.h>

int main(void)
{
	int n ,ai ,i ,max ,min;
	
	long long int sum = 0;
	
	scanf("%d" ,&n);
	
	for(i=0;i<n;i++){
		
		scanf("%d" ,&ai);
		
		sum += ai;
		
		if(i==0){
			
			max = ai;
                        min = ai;


		}
		
		else if(ai>max){
			
			max = ai;
		
		}
		
		else if(ai<min){
			
			min = ai;
			
		}

          }
		
		printf("%d %d %lld\n" ,min ,max ,sum);
		
		return 0;
		
	}
		
	