#include<stdio.h>
#include<limits.h>
#include <stdlib.h>
#include<string.h>

int main(){
	int n,max,min;
	long int sum=0;
	min=INT_MAX;
	max=INT_MIN;
	scanf("%d",&n);
	char *input=(char*)malloc(n*(sizeof(int)+sizeof(' ') ) );
	scanf("\n%[^\n]",input);

	char *p=input;
	int digitcount=0;
	for(int i=0;i<n;i++){
		for(digitcount=0;*(p+digitcount)!=0x20&&*(p+digitcount)!=0x00;digitcount++){
			//空白区切りまでポインタのインデックスを進める
		}
		char num[11]={0};
		strncpy(num,p,digitcount);
		int number =atoi(num);
		if(number>max){
			max=number;
		}
		if(number<min){
			min=number;
		}
		sum+=number;
		p+=digitcount+1;
	}


	printf("%d %d %ld\n",min,max,sum);

	return 0;
}

