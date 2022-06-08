#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
map<string, int> a, b;
string str;
int main(){
int N, M;
cin>>N;
for(int i=1; i<=N; ++i){ cin>>str; a[str]++; }
cin>>M;
for(int i=1; i<=M; ++i){ cin>>str; b[str]++; }
int best = 0;
for(map<string, int>::iterator it=a.begin(); it!=a.end(); ++it){
best = max(best, it->second - b[it->first]);
}
printf("%d\n", best);
return 0;
}