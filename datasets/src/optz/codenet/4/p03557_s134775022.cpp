#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

void NumInput(set<int>& Set, int N, vector<pair<int,int>>& set_pair);
int CountUpOverlap(const vector<pair<int, int>>& set_pair, set<int>::iterator itr);

int main() {

	int N;
	cin >> N;
	set<int>A;
	set<int>B;
	set<int>C;
	vector<pair<int, int>>overlapped_pair_A;
	vector<pair<int, int>>overlapped_pair_B;
	vector<pair<int, int>>overlapped_pair_C;
	NumInput(A, N, overlapped_pair_A);
	NumInput(B, N, overlapped_pair_B);
	NumInput(C, N, overlapped_pair_C);
	int count = 0;
	for (auto itr_A = A.begin(); itr_A != A.end(); itr_A++) {
		for (auto itr_B = B.begin(); itr_B != B.end(); itr_B++) {
			if (*itr_A < *itr_B) {
				for (auto itr_C = C.begin(); itr_C != C.end(); itr_C++) {
					if (*itr_B < *itr_C) {
						count++;
						count = count + 1 * CountUpOverlap(overlapped_pair_A, itr_A) * CountUpOverlap(overlapped_pair_B, itr_B) * CountUpOverlap(overlapped_pair_C, itr_C);
					}
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}

void NumInput(set<int>& Set, int N, vector<pair<int, int>>& set_pair) {
	
	bool IsOverlap = false;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		auto set_insert = Set.insert(num);
		IsOverlap = !(set_insert.second);

		if (IsOverlap) {
			if (set_pair.size() == 0) {
				pair<int, int> pair_push_back = make_pair(*(set_insert.first), 1);
				set_pair.push_back(pair_push_back);
			}
			else {
				bool inserted = false;
				for (int j = 0; j < set_pair.size(); j++) {
					if (*(set_insert.first) == set_pair[j].first) {
						set_pair[j].second++;
						inserted = true;
					}
				}
				if (inserted == false) {
					pair<int, int> pair_push_back = make_pair(*(set_insert.first), 1);
					set_pair.push_back(pair_push_back);
				}
			}
		}
	}
}

int CountUpOverlap(const vector<pair<int, int>>& set_pair, set<int>::iterator itr) {
	int num = 1;
	for (int i = 0; i < set_pair.size(); i++) {
		if ((*itr) == set_pair[i].first) {
			num++;
		}
	}
	return num;
}