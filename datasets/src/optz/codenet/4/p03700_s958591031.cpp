#include <iostream>

using namespace std;

int N;
long int A, B;
long int h[100000];
long int h_max = 0;
long int first;
long int endas;
long int temp;

bool enough(long int x) {
	long int T = 0;
	for (int i = 0; i < N; ++i) {
		int a = h[i] - x * B;
		if (a > 0) {
			T += a / (A - B);
			if (a % (A - B) != 0) {
				++T;
			}
		}
	}
	if (T > x) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i) {
		cin >> h[i];
		if (h[i] > h_max) {
			h_max = h[i];
		}
	}

	first = 1;
	endas = h_max;
	temp = (first + endas) / 2;

	while (1) {
		if (enough(temp)) {
			endas = temp;
		}
		else {
			first = temp + 1;
		}
		temp = (first + endas) / 2;
		if (first == endas) break;
	}
	cout << temp << endl;

}