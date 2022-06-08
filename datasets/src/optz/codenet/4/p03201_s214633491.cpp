#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	long pow_2_10_9 = (long)2*pow(10,9),finded;
	set< long>pow_2_num;
	set<long>num_sequ;
	for(long i = 1;1;++i)//setting power of 2 number series table
	{
		if(pow(2,i)<pow_2_10_9)
		{
			pow_2_num.insert(( long)pow(2,i));
		}
		else break;
	}
	long col_num,single_num,count;
	while(cin>>col_num)//for each group
	{
		num_sequ.clear();
		count = 0;
		for(int i = 0;i<col_num;++i)//for each number
		{
			cin>>single_num;
			if(i == 0)
			{
				num_sequ.insert(single_num);
				continue;
			}
			for(set<long >::iterator iter = num_sequ.begin();iter!=num_sequ.end();)
			{
				if(pow_2_num.find(( long)(single_num+*iter))!=pow_2_num.end())
				{
					count++;finded = *iter;
					num_sequ.erase(finded);
					break;
				}
				++iter;
				if(iter == num_sequ.end())//not find
				{
					num_sequ.insert(single_num);
					break;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}