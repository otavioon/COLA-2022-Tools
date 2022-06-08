#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <string>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	long long A, B;
	cin >> A >> B;
	if (A == 1 && B != 1)
	{
		cout << "Alice" << endl;
		return 0;
	}
	if (A != 1 && B == 1)
	{
		cout << "Bob" << endl;
		return 0;
	}
	if (A > B)
	{
		cout << "Alice" << endl;
		return 0;
	}
		
	if (B > A)
	{
		cout << "Bob" << endl;
		return 0;
	}
		
	cout << "Draw" << endl;


}
