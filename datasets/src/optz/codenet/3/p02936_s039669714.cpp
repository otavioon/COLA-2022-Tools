#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <cmath>
int main() {
	int n, q;
	std::cin >> n >> q;
	
	std::unordered_map<int, int> parent_map;
	for (int i = 0; i < n - 1; i++)
	{
		int parent, child;
		std::cin >> parent >> child;
		parent_map.emplace(child, parent);
	}

	std::unordered_map<int, int> counter_map;
	for (int i = 0; i < q; i++)
	{
		int point, value;
		std::cin >> point >> value;
		counter_map[point] = value + counter_map[point];
	}

	std::vector<int> result;
	std::string ans;
	for (int i = 1; i < n + 1; i++)
	{
		int parent_value = i == 1 ? 0 : result[parent_map[i] -1];
		int res = parent_value + counter_map[i];
		ans += std::to_string(res);
        if (i < n) {
            ans += " ";
        }
		result.push_back(res);
	}
	std::cout << ans << "\n";
}