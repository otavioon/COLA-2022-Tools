#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
 * ????.cpp
 *
 *  Created on: 2011-11-6
 *      Author: ??
 */
int main(){
int A,B,C,D,E;
for (A=1;A<=5;A++){
	for (B=1;B<=5;B++){
		for (C=1;C<=5;C++){
			for (D=1;D<=5;D++){
				for (E=1;E<=5;E++){
					if ((E==2)||(E==3))continue;//???E???2?3
					if ((A==B)||(A==C)||(A==D)||(A==E)||(B==C)||(B==D)||(B==E)||(C==D)||(C==E)||(D==E))continue;//??????????
					if (((((E!=1)&&((A==1)||(A==2)))+(((C==1)||(C==2))&&(A!=5))+(((B==1)||(B==2))&&(B!=2))+
							(((D==1)||(D==2))&&(C==1))+(((E==1)||(E==2))&&(D!=1)))==0)&&
							((E==1)+(A==5)+(C!=1)+(D==1)+(B==2)==2))//????
							{cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;exit(0);}
				}
			}
		}
	}
}
return 0;
}