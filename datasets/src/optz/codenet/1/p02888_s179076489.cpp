#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

map<long long, int> factorization(long long N) {
	map<long long, int> re;
	while (true) {
		if (N % 2 == 0) {
			N /= 2;
			re[2]++;
			if (N == 1) break;
		}
	}
	if (N > 1) re[N]++;
	for (int loop = 3; (long long)loop * (long long)loop <= N; loop += 2) {
		if (N % loop == 0) {
			N /= loop;
			re[loop]++;
			loop -= 2;
			if (N == 1) break;
		}
	}
	if (N > 1) re[N]++;
	return re;
}

struct Memo {
	long long fact = 0;
	long long fact_inv = 0;
	long long inv = 0;
};
class Combination1 {
private:
	int m_module = 1000000007;
	vector<struct Memo> memo;
public:
	int calculate(int, int);
	Combination1(int, int);
};
int Combination1::calculate(int n, int k) {
	return ((memo[n].fact * memo[k].fact_inv) % m_module * memo[n - k].fact_inv) % m_module;
}
Combination1::Combination1(int memo_max, int module = 1000000007) {
	m_module = module;
	memo.push_back({ 1,1,0 });
	memo.push_back({ 1,1,1 });
	for (int loop = 2; loop <= memo_max; loop++) {
		struct Memo temp;
		temp.fact = (memo[loop - 1].fact * loop) % m_module;
		temp.inv = m_module - (memo[m_module % loop].inv * int(m_module / loop)) % m_module;
		temp.fact_inv = (memo[loop - 1].fact_inv * temp.inv) % m_module;
		memo.push_back(temp);
	}
}

class Combination2 {
private:
	int size = 0;
	bool add(int);
public:
	vector<int> sequence;
	bool next_combination(void);
	Combination2(int, int);
};
bool Combination2::add(int index) {
	if (index == (int)sequence.size() - 1 && sequence[index] == size - 1
		|| index < (int)sequence.size() - 1 && sequence[index] == sequence[index + 1] - 1) {
		if (index == 0) {
			return false;
		}
		else {
			bool re = add(index - 1);
			sequence[index] = sequence[index - 1] + 1;
			return re;
		}
	}
	else {
		sequence[index]++;
		return true;
	}
}
bool Combination2::next_combination(void) {
	return (sequence.size() == 0) ? false : add(sequence.size() - 1);
}
Combination2::Combination2(int n, int r) {
	size = n;
	for (int loop = 0; loop < r; loop++) sequence.push_back(loop);
	return;
}

void A_Curtain(void) {

	int A, B; cin >> A >> B;
	
	cout << ((A > B * 2) ? A - B * 2 : 0) << flush;
	return;
}

void B_TAKOYAKI_FESTIVAL(void) {

	int N; cin >> N;
	vector<int> d(N); for (int& it : d)cin >> it;

	int sum = 0;
	sum = (int)pow(accumulate(d.begin(), d.end(), 0), 2);
	for (int it : d) sum -= it * it;
	sum /= 2;

	cout << sum << flush;
	return;
}

void C_Slimes(void) {

	int N; cin >> N;
	vector<char> color(N); for (char& it : color)cin >> it;

	int counter = 1;
	for (int index = 1; index < N; index++) {
		if (color[index] != color[index - 1]) counter++;
	}

	cout << counter << flush;
	return;
}

void D_Triangles(void) {

	int N; cin >> N;
	vector<int> L(N); for (int& it : L)cin >> it;
	sort(L.begin(), L.end());

	/*
	int counter = 0;
	class Combination2 com(N, 3);
	do {
		if (L[com.sequence[0]] + L[com.sequence[1]] > L[com.sequence[2]]) counter++;
	} while (com.next_combination());
	*/

	long long counter = 0;
	for (int a = 0; a < N - 1; a++) {
		for (int b = a + 1; b < N - 1; b++) {
			int start = b, end = N;
			if (L[a] + L[b] > L[b + 1]) {
				while (1) {
					int c = (start + end) / 2;
					if (L[a] + L[b] > L[c]) start = c;
					else					end = c;
					if (start + 1 == end) break;
				}
				counter += (start - b);
			}
		}
	}
	cout << counter << flush;
	return;
}

int main(void) {

	//A_Curtain();
	//B_TAKOYAKI_FESTIVAL();
	//C_Slimes();
	D_Triangles();
	return 0;
}
