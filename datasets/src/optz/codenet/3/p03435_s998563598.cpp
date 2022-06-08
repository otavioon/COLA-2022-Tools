#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int> > ci1(3);
  vector<pair<int, int> > ci2(3);
  vector<pair<int, int> > ci3(3);
  vector<pair<int, int> > cj1(3);
  vector<pair<int, int> > cj2(3);
  vector<pair<int, int> > cj3(3);
  for (int i = 0; i < 3; i++) {
    int tmp;
    cin >> tmp;
    ci1[i] = make_pair(tmp, i);
  }
  for (int i = 0; i < 3; i++) {
    int tmp;
    cin >> tmp;
    ci2[i] = make_pair(tmp, i);
  }
  for (int i = 0; i < 3; i++) {
    int tmp;
    cin >> tmp;
    ci3[i] = make_pair(tmp, i);
  }
  cj1[0] = make_pair(ci1[0].first, 0);
  cj1[1] = make_pair(ci2[0].first, 1);
  cj1[2] = make_pair(ci3[0].first, 2);
  cj2[0] = make_pair(ci1[1].first, 0);
  cj2[1] = make_pair(ci2[1].first, 1);
  cj2[2] = make_pair(ci3[1].first, 2);
  cj3[0] = make_pair(ci1[2].first, 0);
  cj3[1] = make_pair(ci2[2].first, 1);
  cj3[2] = make_pair(ci3[2].first, 2);
  sort(ci1.begin(), ci1.end());
  sort(ci2.begin(), ci2.end());
  sort(ci3.begin(), ci3.end());
  for (int i = 0; i < 3; i++) {
    if (ci1[i].second == ci2[i].second && ci1[i].second == ci3[i].second &&
        ci2[i].second == ci3[i].second)
      continue;
    else {
      cout << "No\n";
      return 0;
    }
  }
  sort(cj1.begin(), cj1.end());
  sort(cj2.begin(), cj2.end());
  sort(cj3.begin(), cj3.end());
  for (int j = 0; j < 3; j++) {
    if (cj1[j].second == cj2[j].second && cj1[j].second == cj3[j].second &&
        cj2[j].second == cj3[j].second)
      continue;
    else {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
