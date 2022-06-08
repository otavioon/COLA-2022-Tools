#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int stick[n];
    for(int i = 0;i < n;i++)
    {
        cin >> stick[i];
    }
    int count = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            for(int k = 0;k < n;k++)
            {
                if(i != j && i != k && j != k && (stick[i] < (stick[j] + stick[k]) && stick[j] < (stick[i] + stick[k]) && stick[k] < (stick[i] + stick[j])))
                {
                    count++;
                }
            }
        }
    }
    cout << count / 6;
    

    return 0;
}