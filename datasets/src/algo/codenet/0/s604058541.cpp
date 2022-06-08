#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  string s;
  ll k;
  cin >> s >> k;
  
  ll n = s.size();    // 元の文字列の長さ
  ll ans = 0;         // 必要な操作回数
  ll top = 0;         // 元の文字列で先頭で同じ文字が連続している数
  ll back = 0;        // 元の文字列で末尾で同じ文字が連続している数

  ll same_char_cnt;   // iから数えて連続する同じ文字の数

  // 元の文字列の中で同じ文字が連続する部分について数を数える
  for (ll i = 0; i < n; i += same_char_cnt) {
    same_char_cnt = 1;
    for (ll j = i + 1; j < n; j++) {
      if (s[i] == s[j])
        same_char_cnt++;
      else
        break;
    }

    // 先頭で連続する同じ文字数をtopに保存する. 先頭に対する操作回数はここでは数えない
    // 例えば元の文字列が、"aaabccdddaa" なら、先頭の"aaa"部分について3を格納する
    if (i == 0) {
      top = same_char_cnt;
      continue;
    }

    // 末尾で連続する同じ文字数をbackに保存する. 末尾に対する操作回数はここでは数えない
    // 例えば元の文字列が、"aaabccdddaa" なら、末尾の"aa"部分について2を格納する
    if (i + same_char_cnt >= n) {
      back = same_char_cnt;
      continue;
    }

    // 文字列の途中で連続する同じ文字に対する操作回数をansに加算する.
    // 例えば元の文字列が、"aaabccdddaa" なら、"b", "cc", "ddd" の3つの部分について計算を行う
    ans += same_char_cnt / 2;
  }

  if (top == n) {   // 元の文字列が1つの文字だけで構成される場合
    ans = (n * k) / 2;
  } else {
    // 元の文字列の途中部分に対する操作回数をk倍する
    ans *= k;

    if (s[0] == s[n - 1]) 
      // 先頭と末尾の文字が一致する場合、文字列の接点の操作回数を分けて考える必要がある
      // 先頭と末尾の文字が一致する場合の接点の操作回数は(top + back) / 2 回となる
      // "aaabccdddaa"+"aaabccdddaa"の接点は、"aaaaa"となるので、(3+2)/2 の2回操作する
      // 文字列の接点は、k-1 回あるので、接点の操作回数の和は、(top + back) / 2 * (k - 1) となる
      ans += (top + back) / 2 * (k - 1) + top / 2 + back / 2;
      
    else
      // 先頭と末尾の文字が一致しない場合は、先頭、末尾の操作回数は別々に考えればよい
      ans += k * (top / 2 + back / 2);
      
  }

  cout << ans << endl;

  return 0;
}