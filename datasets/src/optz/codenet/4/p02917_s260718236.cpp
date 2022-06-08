#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>

using namespace std;






int i, n, goukei,suretu[600000];
string mozi,kopi;
int main() {
	cin >> n;
	for (i = 0; i < n-1; i++) {
		cin >>suretu[i];		
	}
	goukei = suretu[0];
	goukei = goukei + suretu[n - 1];
	for (i = 1; i < n-1; i++) {
		if (suretu[i] > suretu[i - 1]) {
			goukei = goukei + suretu[i - 1];
		}
		else {
			goukei = goukei + suretu[i];
		}
	}
	if (n == 1) {
		cin >> goukei;
	}
	printf("%d\n",goukei);

	return 0;
}
