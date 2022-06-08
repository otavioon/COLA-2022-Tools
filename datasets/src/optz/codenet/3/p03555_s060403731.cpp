#include <iostream>
#include <vector> 
#include <algorithm>
#include <numeric>


int main()
{
  auto n = 0;
  std::cin >> n;

  auto top = std::vector<int>(n);
  for (auto i = 0; i < n; ++i) std::cin >> top[i];
  std::sort(top.begin(), top.end());

  auto mid = std::vector<int>(n);
  for (auto i = 0; i < n; ++i) std::cin >> mid[i];
  std::sort(mid.begin(), mid.end());

  auto bot = std::vector<int>(n);
  for (auto i = 0; i < n; ++i) std::cin >> bot[i];
  std::sort(bot.begin(), bot.end());

  auto count = int(0);

  for (auto it_m = mid.begin(); it_m != mid.end(); ++it_m)
  {
    auto t_lower = std::lower_bound(top.begin(), top.end(), *it_m);
    auto top_num = 0;
    if (*t_lower >= *it_m && t_lower != top.end())
    {
      t_lower--;
      top_num = t_lower - top.begin() + 1;
    }
    else
      top_num = t_lower - top.begin();

    auto b_upper = std::upper_bound(bot.begin(), bot.end(), *it_m);
    auto bot_num = 0;
    if ((*b_upper == *it_m) && b_upper < bot.end() - 1)
    {
      b_upper++;
      bot_num = bot.end() - b_upper;
    }
    else
      bot_num = bot.end() - b_upper;

    count += top_num * bot_num;
  }

  std::cout << count << std::endl;

  return 0;
}