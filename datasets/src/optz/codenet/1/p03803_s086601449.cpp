#include <stdio.h>
int main(void)
{
	int a,b,c,A,B,C,i;
	scanf("%d%d",&a,&b);
	c=a;
	for(i=1; i<=2; i++){
		switch(c){
			case 2:
				C=1;
				break;
			case 3:
				C=2;
				break;
			case 4:
				C=3;
				break;
			case 5:
				C=4;
				break;
			case 6:
				C=5;
				break;
			case 7:
				C=6;
				break;
			case 8:
				C=7;
				break;
			case 9:
				C=8;
				break;
			case 10:
				C=9;
			break;
				case 11:
				C=10;
				break;
			case 12:
				C=11;
				break;
			case 13:
				C=12;
				break;
			case 1:	
				C=13;
				break;
		}
		if(i==1){
			c=b;
			A=C;
		}
		if(i==2){
			B=C;
		}
	}
	if(A>B){
		printf("Alice\n");
	}
	if(A<B){
		printf("Bob\n");
	}
	if(A==B){
		printf("Draw\n");
	}
	return 0;
}