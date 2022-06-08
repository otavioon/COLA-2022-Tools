#include <cstdio>

struct M
{
  int value[9];
  int operator()(int i, int j)
  {
    return value[(i % 3) * 3 + (j % 3)];
  }
};

int main()
{
  M m;
  for (int i = 0; i < 9; ++i)
  {
    scanf("%d", m.value + i);
  }

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if
      (
        m(i, j) - m(i + 1, j) != m(i, j + 1) - m(i + 1, j + 1) ||
        m(i, j) - m(i, j + 1) != m(i + 1, j) - m(i + 1, j + 1)
      )
      {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}