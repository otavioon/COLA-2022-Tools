#include<stdio.h>
#include<vector>
#include<iostream> //c++
#include<algorithm>
/*
int main(){
	int a=0;
	char A[5];
	for (int i = 0; i < 5; i++) {
		scanf("%c\n", &A[i]);
	}
	
	for(int i = 0; i < 5; i++) {
		if (A[i] =='A' &&A[i + 1]=='C') {
			a = 1;
		
		}
	}
	if (a == 1) {
		printf("Yes");

	}
	else {
		printf("No");
	}
}*/

using namespace std;
/*int main() {
	int g;
	int  N,Num=0;
	vector<int>a;
	cin >> N;
	for (int i = 0; i < N;i++) {

		cin >> g;

		a.push_back(g);
	

	}
	int t,p=0;
	while (true) {
		t=a[p] ;
		a[p] = -1;
		p = t;
		if (p == -1) {
			Num = -1;
			break;
		}
			Num++;
			if (p == 2) {
				break;
			}
			p = p - 1;
	}
	cout << Num;
	



int main() {
	
		long long N, g;
	vector<int>a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> g;
		a.push_back(g);
	}
	sort(a.begin(), a.end());
	long long Num1 = 0, Num2 = 0, Num;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[i + 1] && a[i] >= Num1 && i != N - 1) {
			Num2 = Num1;
			Num1 = a[i];
			i++;
		}
	}
	Num = Num1 * Num2;
	cout << Num;
	return 0;
}
	

int main(){vector<int>S;
	int count=0;
	int g;

		cin >> g;
		S.push_back((g %100000)/10000);
		S.push_back((g %10000)/1000);
		S.push_back((g %1000)/100);
		S.push_back((g %100)/10);
		S.push_back((g %10)/1);
		S.push_back((g %1000000)/100000);
		
		
		for (int i = 0; i < 6; i++) {
			if (S[i] == 1) {

				count++;
			}
		}



	cout << count;






*/


int main(){
int num;
	int N, M;
	cin >> N;
	
	char t[100][11];
	char s[100][11];
	for (int i = 0; i < N; i++) {
		scanf("%s", s[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%s", t[i]);
	}
	int count=0;
	int max=0;
	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 11; j++) {
				if (s[k][j] == t[i][j]) {
					count++;

				}
			}
			if (count == 10) {
				num++;
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 11; j++) {
				if (s[k][j] == t[i][j]) {
					count++;

				}
			}
			if (count == 10) {
				num--;
			}
		}
		count = 0;
		if (max < num){
		
		}
		num = 0;
	}
	count >> max;
}