#include <iostream>
#include <sstream> // std::stringstream
#include <istream> // std::getline
#include <set>

using namespace std;

bool is_valid(const int n, const set<int>& set_n) {
	auto str = to_string(n);
	bool is_valid = true;
	auto itr = set_n.begin();
	for (itr; itr != set_n.end(); ++itr) {
		if(str.find(to_string(*itr)) != string::npos) is_valid = false;
	}
	return is_valid;
}

int main() {
	int n, k;
	cin >> n >> k;
	string buf;
	set<int> set_n;

	while (std::getline(cin, buf, ' ')) {
		set_n.insert(stoi(buf));
	}

	while(!is_valid(n, set_n)) {
		n += 1;	
	}
	cout << n << endl;
	return 0;
}