#include <stdio.h>

int main(void)
{
	int a;
	int n;
	int c;
	int max;
	int saisyou;
	int goukei;
	goukei = 0;
	max = 0;
	saisyou = c;
	
	
		
	scanf("%d", &a);
	
	for (n = 1; n <= a; n++){
		scanf("%d", &c);
		if(max < c){
			max = c;
		}
		if(saisyou > c){
			saisyou = c;
		}
		goukei = goukei + c;
	}
	printf("%d %d %d\n", saisyou, max, goukei);
	
	
	return (0);
}