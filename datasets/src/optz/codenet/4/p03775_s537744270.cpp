#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
long long int  result[2],N, A, B,myMin;




int main() {
	cin >> N;

	myMin = 100;

	for (int i = 1; i <=100000; i++) {
		if (0 == N%i && 0 < N / i) {
			A = N / i;

			if (1 <= A &&  9>=A ) {
				result[0] = 1;
			}
			if (1 <= A / 10 && 9 >= A / 10 ) {
				result[0] = 2;
			}
			if (1 <= A / 100 && 9 >= A / 100 ) {
				result[0] = 3;
			}
			if (1 <= A / 1000 && 9 >= A / 1000 ) {
				result[0] = 4;
			}
			if (1 <= A / 10000 && 9 >= A / 10000) {
				result[0] = 5;
			}

			if (1 <= A / 100000 && 9 >= A / 100000 ) {
				result[0] = 6;
			}
			if (1 <= A / 1000000 && 9 >= A / 1000000) {
				result[0] = 7;
			}
			if (1 <= A / 10000000 && 9 >= A / 10000000 ) {
				result[0] = 8;
			}
			if (1 <= A / 100000000 && 9 >= A / 100000000 ) {
				result[0] = 9;
			}
			if (1 <= A / 1000000000 && 9 >= A / 1000000000) {
				result[0] = 10;
			}
			if (1 <= A / 10000000000 && 9 >= A / 10000000000) {
				result[0] = 11;
			}


			if (1 <= i && 9 >= i ) {
				result[1] = 1;
			}
			if (1 <= i / 10 && 9 >= i / 10) {
				result[1] = 2;
			}
			if (1 <= i / 100 && 9 >= i / 100 ) {
				result[1] = 3;
			}
			if (1 <= i / 1000 && 9 >= i / 1000) {
				result[1] = 4;
			}
			if (1 <= i / 10000 && 9 >= i / 10000) {
				result[1] = 5;
			}

			if (1 <= i / 100000 && 9 >= i / 100000) {
				result[1] = 6;
			}
			

			if (myMin > max(result[0], result[1])) {
				myMin = max(result[0], result[1]);
			}

		}
		

	}

	

	cout <<myMin << endl;

	return 0;
}


