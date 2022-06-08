#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

int main(void){
    string n;
    int k;
    cin >> n >> k;
    bool a[10];
    for(int i = 0; i < 10; i++){
        a[i] = true;
    }

    for(int i = 0; i < k; i++){
        int d;
        cin >> d;
        a[d] = false;
    }

    const char *str = n.c_str();
    string answer;
    for(int j = 0; j < n.size(); j++){
        int num = str[j] - '0';

        for(int i = 0; i < 10; i++){
            if(a[i] == true && i >= num){
                char num1 = '0' + i;
                answer.push_back(num1);
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}