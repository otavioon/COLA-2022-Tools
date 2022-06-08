#include <iostream>
#include <set>
#include <map>

using namespace std;

bool likes(int i, set<int> dislike)	{
	int temp = i;
  	int digit;
  	while (temp != 0)	{
    	digit = temp % 10;
      	temp /= 10;
     	if (dislike.count(digit) != 0)
          	return false;
    }
  	return true;
}

int main()	{
  	int n, k;
  	set<int> dislike;
  	cin >> n >> k;
  	int temp;
  	for (int i = 0; i < k; i++)	{
    	cin >> temp;
      	dislike.insert(temp);
    }
  	for (int i = n;; i++)	{
    	if (likes(i, dislike))	{
        	cout << i << endl;
          	break;
        }
    }
  	return 0;
}