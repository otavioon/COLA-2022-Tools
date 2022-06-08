#include <iostream>
#include <vector>

int button(std::vector<int> v, int num, int count){
	// 2が押されたら終了
	if (num == 2) {
		return count;
	}
	// 全てのボタンを押して2にたどり着かなかったらおかしい
	else if (count > v.size()) {
		return -1;
	}
	else {
		return button(v, v[num-1], count+1);
	}
}

int main(int argc, char const *argv[]) {
	int n,temp;
	bool flag;
	std::cin >> n;
	std::vector<int> v;
	for (size_t i = 0; i < n; i++) {
		std::cin >> temp;
		v.push_back(temp);
	}
	std::cout << button(v,1,0) << '\n';
	return 0;
}
