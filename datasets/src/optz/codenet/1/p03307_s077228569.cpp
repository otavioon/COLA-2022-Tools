#include<iostream>
using namespace std;
int main(void)
{
	int n, i;
	cin >> n;
	for (i = 1; i < 100000000; i++)
	{
		if (i % 2 == 0 && i%n == 0)
		{
			cout << i << endl;
			break;
		}
	}
}