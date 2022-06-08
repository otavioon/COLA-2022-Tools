#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>

int isCheck = 1;
bool checkBit(int A) {
  bool check = false;
  if (!A) return check;		// 0は無視
  if ((A & isCheck) == isCheck) return check;	// 一番左端が1ビット = 奇数
  for (int i = 1; i < 32; ++i) {
  	A = A >> 1;
    if ((A & isCheck) == isCheck) {
      if (check) return false;
      check = true;
    }
    if (!A) {
      isCheck = isCheck | (1 << (i-2));
      return check;
    }
  }
  isCheck = isCheck | (1 << 30);
  return check;
}

int countPair(const std::vector<int> &A)
{
  int count = 0;
  std::string str;
  for(auto i = A.begin(); (i+1) != A.end(); ++i) {
    for (auto j = i + 1; j != A.end(); ++j) {
      if (checkBit((*i) + (*j))) {
        // std::cout << (*i) + (*j) << ":" << "true" << std::endl;
        // std::cout <<"isCheck:" << static_cast<std::bitset<8> >(isCheck) << std::endl;
        ++count;
      // } else {
      //  std::cout << (*i) + (*j) << ":" << "false" << std::endl;
      }
    }
  }
  return count;
}

int main()
{
  	int N;
  	std::vector<int> A;
  
  	std::cin >> N;
  	for(int i = 0; i < N; ++i) {
      int a;
      std::cin >> a;
      A.push_back(a);
    }
  
    // 出力
    std::cout << countPair(A) << std::endl;
    return 0;
}