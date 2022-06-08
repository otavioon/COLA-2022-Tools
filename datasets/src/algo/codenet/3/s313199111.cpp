#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int *array1 = (int *)malloc(sizeof(int)*N);
    int *array2 = (int *)malloc(sizeof(int)*N);
    int *array3 = (int *)malloc(sizeof(int)*N);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < N; j++)
        {
            if(i == 0) cin >> array1[j];
            else if(i == 1) cin >> array2[j];
            else if(i == 2) cin >> array3[j];
        }
    sort(array1, array1+N);
    sort(array2, array2+N);
    sort(array3, array3+N);
    
    int count1=0, count2=0, total=0;
    for(int i = 0; i < N; i++)
    {
        count1 = 0; count2 = 0;
        for(int j = 0; j < N; j++)
        {
            if(array2[i] > array1[j]) count1++;
            else break;
        }
        for(int m = N-1; m >= 0; m--)
        {
            if(array3[m] > array2[i]) count2++;
            else break;
        }
        total += (count1 * count2);
    }
    cout << total << endl;
}

