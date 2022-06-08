#include<iostream>
using namespace std;

int input() {
	int input[51][2];
	cin >> input[0][0] >> input[0][1];								//まずnとr
	if (input[0][0] == 0 && input[0][1] == 0) {
		return 0;
	}
	/*
	input[0][0] = 0;
	input[0][1] = 0;
	*/
	for (char pos = 1; pos <= input[0][1]; pos++) {
		cin >> input[pos][0] >> input[pos][1];
	}																//ここまで入力

	/*シャッフルもどし*/
	int whtop = 1;													//1番目≠要素
	whtop = input[input[0][1]][0];
	input[0][1]--;
	while (input[0][1] != 0) {

		if (input[input[0][1]][1] >= whtop) {
			whtop = input[input[0][1]][0] + whtop - 1;
		}
		else {
			whtop = whtop - input[input[0][1]][1];
		}
		input[0][1]--;
	}
	return input[0][0]-whtop+1;
}




int main()
{
	int output[100];
	char topos = 0;
	while (1) {
		int check;
		check=input();
		if (check == 0)break;
		else {
			output[topos] = check;
			topos++;
		}
	}

	char sendpos = 0;
	while (sendpos < topos) {
		cout << output[sendpos] << endl;
		sendpos++;
	}

}
