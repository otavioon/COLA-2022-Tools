#include<cstdio>

using namespace std;

int main(){
	int c[3][3];
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) scanf("%d", &c[i][j]);
	int b1 = c[0][0], b2 = c[0][1], b3 = c[0][2];
	if(c[1][0] - b1 == c[1][1] - b2 && c[1][1] - b2 == c[1][2] - b3 &&
	c[2][0] - b1 == c[2][1] - b2 && c[2][1] - b2 == c[2][2] - b3) puts("Yes");
	else puts("No");
	return 0;
}