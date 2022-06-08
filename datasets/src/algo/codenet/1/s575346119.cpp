#include<iostream>
using namespace std;

int main() {
	int c[3][3];
	for (int i = 0;i < 9;i ++) cin >> c[i / 3][i % 3];
	for (int i = 0;i < 2;i ++) {
		for (int j = 0;j < 2;j ++) {
			if (c[i][j] - c[i][j + 1] != c[i + 1][j] - c[i + 1][j + 1]) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

まず、a_1を0とする
この時b_1=c_11、b_2=c_12、b_3=c_13となる
その時、c_21とc_22とc_23の差は式よりc_11とc_12とc_13に等しい c_3jも同様
上が成立するなら全てのaとbのパターンが存在するし、成立しないなら矛盾がある
よってこれは必要十分条件を満たす
*/