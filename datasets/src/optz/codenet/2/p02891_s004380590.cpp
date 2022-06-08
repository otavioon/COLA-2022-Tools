#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    int size = s.size();

    s = s + ' ';
    vector<int> cnt(size, 0);

    bool start=false;
    bool end=false;

    int tmp = -1;

    long long sum = 0;

    bool flag=true;
    int count=1;
    for(int i=1; i < size; i++){
        if(s.at(0) == s.at(i)){
            count++;
        }
        else{
            break;
        }
    }

    for(int i=size-1; i > 0; i--){
        if(s.at(0) == s.at(i)){
            count++;
        }
        else{
            break;
        }
    }

    for(int j=0; j < size-1; j++){
        if(s.at(j) != s.at(j+1)){
            start = false;
        }
        else if(s.at(j) == s.at(j+1) && tmp <= j){
            start = true;
        }


        for(int i=j; i < s.size(); i++){
            if(s.at(j) == s.at(i) && start == true){
                cnt.at(j)++;
                end = true;
  //            cout << cnt.at(j) << endl;
            }
            else if(s.at(j) != s.at(i)  && end == true){
                start = false;
                end = false;
                tmp = i;
                cnt.at(j) = cnt.at(j) / 2;
            }
        }
    }

    for(int c: cnt){
//        cout << c << endl;
        sum += c;
    }

    if(size == 1){
        sum = k*size / 2; 
    }
    else{
        sum = k * sum;
        if(count % 2 == 0){
//            sum += (k-1);
//        cout << count << endl;
        }
    }

    cout << sum << endl;

}