#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main() {
	int A=0,B=0,C=0;//????A,B,C???
	int As=0,Bs=0,Cs=0;//??????????????
	int dA=0,dB=0,dC=0;//????????
	for(A=1;A<=3;A++){
		for(B=1;B<=3;B++){
			for(C=1;C<=3;C++){
				As=(B>A)+(C==A);
				Bs=(A>B)+(A>C);
				Cs=(C>B)+(B>A);
				if(!(A<=B&&As<=Bs||A<=C&&As<=Cs||
					 B<=A&&Bs<=As||B<=C&&Bs<=Cs||
					 C<=A&&Cs<=As||C<=B&&Cs<=Bs))//???????????????????????????
				{
					dA=A;
					dB=B;
					dC=C;
				}//??????????
			}
		}
	}
	if (dA>=dB&&dB>=dC)
		cout << "CBA" << endl;
	if (dA>=dC&&dC>=dB)
		cout << "BCA" << endl;
	if (dB>=dA&&dA>=dC)
		cout << "CAB" << endl;
	if (dB>=dC&&dC>=dA)
		cout << "ACB" << endl;
	if (dC>=dA&&dA>=dB)
		cout << "BAC" << endl;
	if (dC>=dB&&dB>=dA)
		cout << "ABC" << endl;//??A,B,C????????????ABC
	return 0;
}
