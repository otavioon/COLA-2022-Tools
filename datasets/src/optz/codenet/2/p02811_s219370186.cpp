
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> func_vec(const string str, const string substr) {
    vector<int> result;

    int substrsize = substr.size();
    int pos = str.find(substr);

    while (pos != string::npos) {
        //Appendしていく
        result.push_back(pos);
        //文字検索位置を更新する
        pos = str.find(substr, pos + substrsize); 
    }
    return result;
}

int main() {
    int N;
    string str ;
    string substr = "ABC";
    cin >> N >> str;

    vector<int> vec = func_vec(str, substr);
    cout << vec.size()<< endl;
    /*for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }*/
}




/*
#include <iostream>
using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;
    if (500 * K>=N)
        cout << "Yes\n";
    else
        cout << "No\n";
}*/
