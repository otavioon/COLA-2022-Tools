#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
	int  A, B ;
scanf("%d%d", &A, &B);
if(A<=13 &&((A==1&&B!=1)||(A>B && B!=1))){	
printf("Alice");
	}else if (B<=13 &&((B==1&&A!=1)||(B>A &&B!=1))){
		printf("Bob");
	}else if (A=B ||(A==1&&B==1)){
		printf("Draw");
	}
	return 0;
}
    