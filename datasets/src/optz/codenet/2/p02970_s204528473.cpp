/* C++14 (Clang 3.8.0) for AtCoder */

#include <iostream>
#include <vector>
#include <string>
// #include <cmath>
// #include <math.h>
// #include <algorithm>
// #include "./Debug.h"

namespace AtCoder {
	using Input = std::vector<std::string>;
	using Num = std::vector<int>;

	Input input(void) {
		Input result;
		{
			std::string buf = "", row = "";
			std::getline(std::cin, buf);
			for (unsigned int i = 0; i < buf.size(); i++) {
				if (' ' == buf[i]) {
					result.push_back(row);
					row = "";
				} else {
					row += buf[i];
				}
			}
			result.push_back(row);
		}
		return result;
	}

	Num replaceToInteger(Input original = { "" }) {
		Num result;
		for (unsigned int i = 0; i < original.size(); i++) {
			result.push_back(atoi(original[i].c_str()));
		}
		return result;
	}
}

int main(void) {

	AtCoder::Num s = AtCoder::replaceToInteger(AtCoder::input());

	const int n = s[0], d = s[1];

	int ans = 0, buf = 0;

	buf = d * 2 + 1;

	ans = n / buf;
	if (0 != n % buf) {
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
