#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int makeNum(vector<int> input)
{
    int res = 0;
    reverse(input.begin(), input.end());
    for(int i = input.size(); i > 0; i--)
    {
        res = res + (input[i-1] * pow(10,i-1));
    }
    return res;
}


int digit(int N, vector<int> dislike)
{
    vector<int> numVec;
    int num = N;
    if(num == 0)
    {
        numVec.push_back(0);
    } else
    {
        while(num > 0)
        {
            numVec.push_back(num%10);
            num /= 10;
        }
    }

    reverse(numVec.begin(), numVec.end());

    bool noNeed = true;
    for(int d : numVec)
    {
        if(find(dislike.begin(), dislike.end(), d) != dislike.end())
        {
            noNeed = false;
            break;
        }
    }

    if(noNeed) return N;

    bool greater = false;
    int idx = 0;
    while(!greater)
    {
        while(find(dislike.begin(), dislike.end(), numVec[idx]) != dislike.end())
        {
            numVec[idx]++;
        }

        //if(numVec[idx] == 10 && N != 9999)
        {
            //return digit(makeNum(numVec), dislike);
        }

        if(makeNum(numVec) > N)
        {
            greater = true;
            break;
        }
        idx++;
    }
    int cntr = 0;

    while(find(dislike.begin(), dislike.end(), cntr) != dislike.end())
    {
        cntr++;
    }

    for(int i = idx+1; i < numVec.size(); i++)
    {
        numVec[i] = cntr;
    }


    return makeNum(numVec);

}

int main() {

    int N, K;

    cin >> N >> K;

    vector<int> vec(K);

    for(int &d : vec)
        cin >> d;

    cout << digit(N, vec);

    return 0;
}