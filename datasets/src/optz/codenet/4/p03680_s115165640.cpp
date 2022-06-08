#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> light(N);
    vector<bool> lighting(N);
    lighting.at(0) = true;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        light.at(i) = num - 1 ;
    }

    int count = 0;
    int i = 0;
    while(true){
        int nextLightNo;
        int past = -1;

        if(lighting.at(i) == true){
            nextLightNo = light.at(i);
            past = nextLightNo;
            lighting.at(nextLightNo) = true;
            lighting.at(i) = false;
            count++;
            i = -1;
        }

        i++;
        if(lighting.at(1) == true || count > 10000){
            break;
        }
    }

    if(count <= 10000){
        cout << count << endl;
    }else
    {
        cout << -1 << endl;
    }
    
    
}