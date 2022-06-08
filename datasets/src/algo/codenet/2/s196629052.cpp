#include <iostream>
#include <set>
using namespace std;

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  multiset<int> st;
  for(int i = 0; i < n; ++i)
  {
    int a;
    cin >> a;
    st.insert(a);
  }

  int ans = 0;
  while (!st.empty())
  {
    int last = *(--st.end());
    st.erase(--st.end());
    int two = 1;
    while (two <= last)
      two <<= 1;
    auto itr = st.find(two - last);
    if (itr == st.end())
      continue;
    ++ans;
    st.erase(itr);
  }
  cout << ans;
  return 0;
}
