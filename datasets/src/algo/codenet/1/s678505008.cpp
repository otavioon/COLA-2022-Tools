#include <cstdio>

int main()
{
	int grid[3][3], x[3], y[3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	for(int i=0; i<3; i++){
		x[i] = grid[i][0] - (grid[i][1] + grid[i][2])/2;
		y[i] = grid[0][i] - (grid[1][i] + grid[2][i])/2;
	}
	bool flag = true;
	if(x[0] != x[1] || x[1] != x[2]){
		flag = false;
	}	
	if(y[0] != y[1] || y[1] != y[2]){
		flag = false;
	}
	if(flag) printf("Yes\n");
	else printf("No\n");

	return 0;
}