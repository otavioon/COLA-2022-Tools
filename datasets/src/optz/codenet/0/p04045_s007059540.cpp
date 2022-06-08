#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printAll(const vector<int>&);

int main(){
  string N;
  string res;
  int K;
  cin >> N >> K;

  int temp;
  vector<int> like_list;

  for (int i = 0; i < 10; ++i){
    like_list.push_back(i);
  }

  for (int i = 0; i < K; ++i) {
    cin >> temp;
    like_list.erase(remove(like_list.begin(), like_list.end(), temp));
    }

  //printAll(like_list);

  for (int i = 0; i < N.size(); ++i){
    for (int j = 0; j < like_list.size(); ++j){
      if (i == 0 and like_list[j] == 0){
	continue;
      }else if (N[i] >= like_list[j]){
	cout << like_list[j];
	break;
      }
    }
  }

}


/*    
void printAll(const std::vector<int>& ary) {
    using std::cout; using std::endl;
    cout << "要素数[ " << ary.size() << " ]" << endl;
    cout << "許容量[ " << ary.capacity() << " ]" << endl;
    cout << "要素[ ";
    // 配列と同じようなループが可能
    for (unsigned int i = 0; i < ary.size(); ++i)
        cout << ary[i] << " ";
    cout << "]" << endl << endl;
}
*/
