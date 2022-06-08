#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <set>
#include <map>

std::multiset<int, std::greater<int>> list;
int N;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int tmp;
    scanf(" %d", &tmp);
    list.insert(tmp);
  }
  int count = 0;
  for(auto it = list.begin(); it != list.end();) {
    int v = *it;
    it = list.erase(it);
    int corresp = v ^ 
      (
      ((1 << (32 - __builtin_clz(v))) - 1) & 
      ~((1 << (__builtin_ctz(v) + 1)) - 1)
    );
    //printf("%d -> %d %d\n", v, corresp, list.size());
    auto fit = list.find(corresp);
    if(fit != list.end()) {
      if(it == fit) it = list.erase(fit); 
      else list.erase(fit);
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}