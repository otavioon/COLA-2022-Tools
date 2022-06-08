#include<stdio.h>

int main(){
	int i, x;
	int data[3000];
	int data2[3000];
	for(i = 0;i < 3000;i++){
		scanf("%d %d", &data[i], &data2[i]);
		if(data[i] == 0 && data2[i] == 0) break;
	}
	for(i = 0;i < 3000;i++){
		if(data[i] == 0 && data2[i] == 0){
			break;
		}else {
			if(data[i] > data2[i]){
				x = data[i];
				data[i] = data2[i];
				data2[i] = x;
			}
		}
		printf("%d %d\n", data[i], data2[i]);
	}
	return 0;
}