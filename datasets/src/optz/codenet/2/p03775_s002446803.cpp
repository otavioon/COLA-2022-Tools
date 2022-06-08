#include <bits/stdc++.h>
using namespace std;

vector<long long> cds;
int minDigits = 1e9;
long long N;

void dfs(long long currentNum, int index)
{
    long long currentCd = cds.at(index);

    int currentCdCount = 1;
    index++;
    while(index < cds.size()){
        if(cds.at(index) != currentCd){
            break;
        }
        currentCdCount++;
        index++;
    }
    if(index == cds.size()){
        for(int i = 0; i <= currentCdCount; i++)
        {
            long long opNum = N / currentNum;
            long long biggerNum = max(opNum, currentNum);
            int digits = 1;
            while(biggerNum >= 10)
            {   
                biggerNum /= 10;
                digits++;
            }
            minDigits = min(minDigits, digits);
            currentNum *= currentCd;
        }
        return;
    }
    for (int i = 0; i <= currentCdCount; i++)
    {
        dfs(currentNum, index);
        currentNum *= currentCd;
    }
};

int main()
{
    cin >> N;
    cds = vector<long long>(0);

    long long workN = N;
    for (int i = 2; i * i <= workN; i++)
    {
        while (workN % i == 0)
        {
            cds.push_back(i);
            workN /= i;
        }
    }
    if (workN > 1)
    {
        cds.push_back(workN);
    }
    dfs(1, 0);
    cout << minDigits << endl;
    return 0;
}