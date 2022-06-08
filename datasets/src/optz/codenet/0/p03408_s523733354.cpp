//インクルード
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

//型宣言
typedef long long ll;
typedef unsigned long long ull;
typedef std::string string;
typedef ull answerType;

//変数宣言
ll N;
ll M;
std::vector<string> s;
std::vector<string> t;
answerType answer;

//関数のプロトタイプ宣言
//入力の取得
void getInput();
//答えを求める
answerType calcAnswer();

//メイン関数
int main() {
	//入力の取得
	getInput();

	//答え
	answerType answer = calcAnswer();

	//答えの出力
	std::cout << answer << std::endl;

	//正常終了
	return EXIT_SUCCESS;
}

//入力の取得
void getInput() {
	std::cin >> N;

	for(ll i=0; i<N; ++i) {
		string temp;
		std::getline(std::cin, temp);
		s.push_back(temp);
	}

	std::cin >> M;

	for(ll i=0; i<M; ++i) {
		string temp;
		std::getline(std::cin, temp);
		t.push_back(temp);
	}
}

//答えを求める
answerType calcAnswer() {
	ull maxValue = 0;
	std::vector<string> word;
	for(ull i=0; i<s.size(); i++) {
		const string target = s[i];
		if(std::find(word.begin(), word.end(), target) != word.end()) {
			continue;
		}
		std::vector<string> tempAdd;
		std::vector<string> tempSub;
		copy_if(s.begin(), t.end(), back_inserter(tempAdd), [target](string x){return x == target;});
		copy_if(s.begin(), t.end(), back_inserter(tempSub), [target](string x){return x == target;});
		if(maxValue < tempAdd.size() - tempSub.size()) {
			maxValue = tempAdd.size() - tempSub.size();
		}
	}
	return maxValue;
}
