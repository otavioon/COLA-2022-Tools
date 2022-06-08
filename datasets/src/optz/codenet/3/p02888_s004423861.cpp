#include<iostream>
#include<string>
#include<array>
#include<algorithm>

using namespace std;

int main()
{
	int n, a = 0, b = 0, c = 0, count = 0;
	float abc = 0;
	cin >> n;
	array<int, 2000> l;
	l.fill(0);
	for(a = 0; a < n; a++)
		cin >> l[a];
	
	sort(l.begin(), l.end(), greater<int>());
	for(a = 0; a < n; a++)
	{
		for(b = a+1; b < n; b++)
		{
			for(c = b+1; c < n; c++)
			{
				abc = (l[a] + l[b] + l[c])*0.5;
				//cout << l[a] << " " << l[b] << " " << l[c] << endl;
				if(l[a] < abc && l[b] < abc && l[c] < abc)
				{
					count++;
				}else{
					break;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}

