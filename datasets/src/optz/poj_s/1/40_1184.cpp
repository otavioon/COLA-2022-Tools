#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int A,B,C,D,E,C1,C2,C3,C4,C5;
	for(int A=1;A<=5;A++)
		for(int	B=1;B<=5;B++)
			for(int C=1;C<=5;C++)
				for(int D=1;D<=5;D++)
					for(int E=1;E<=5;E++)
					{
						C1=(A==2||A==1)&&(E==1)||((A!=1)&&(A!=2))&&(E!=1);
						C2=(B==2)||(B!=1)&&(B!=2);
						C3=((C==1||C==2)&&A==5)||((C!=1&&C!=2)&&A!=5);
						C4=((D==1||D==2)&&(C!=1))+((D!=1&&D!=2)&&C==1);
						C5=((D!=1&&E!=1)||(E==1&&D==1))&&(E!=2)&&(E!=3);
						//cout<<C1<<" "<<C2<<" "<<C3<<" "<<C4<<" "<<C5;
						if(C1+C2+C3+C4+C5==5&&A+B+C+D+E==15&&A*B*C*D*E==1*2*3*4*5)
							cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<endl;
					}
					return 0;
}
							
		