#include <bits/stdc++.h>

using namespace std;

char s[105], k[20];

int main(){
	int tmp = 0;
	scanf("%s",s);
	scanf("%s",k);
	for(int i = 0; i <= strlen(s); i++){
		if(s[i] == '1'){
			if(strlen(k) == 1){
				printf("%c",s[i]);
				break;
			} else {
				continue;
			}
		} else {
			printf("%c",s[i]);
			break;
		}
	}
	return 0;
}