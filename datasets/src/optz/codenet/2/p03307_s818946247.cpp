#include <bits/stdc++.h>
using namespace std;

int main(){
vector<int> V;
int N;
cin >> N;
for (int i = 0; i < N; ++i){
int tmp;
cin >> tmp;
V.push_back(tmp);
}
int MAX = *max_element(V.begin(),V.end());
int MIN = *min_element(V.begin(),V.end());
cout << MAX - MIN << endl;
return 0;
}