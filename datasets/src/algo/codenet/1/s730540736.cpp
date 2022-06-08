#include<cstdio>
int a[3][3],A[3],B[3];
int main(){
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
		scanf("%d",&a[i][j]);
	for(A[0]=-1000; A[0]<=1000; A[0]++){
		B[0] = a[0][0] - A[0];
		B[1] = a[0][1] - A[0];
		B[2] = a[0][2] - A[0];
		A[1] = a[1][0] - B[0];
		A[2] = a[2][0] - B[0];
		bool ff = true;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if(a[i][j] != A[i] + B[j])
					ff = false;
		if(ff){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
