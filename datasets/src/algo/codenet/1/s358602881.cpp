#include<algorithm>
#include<bits/allocator.h>
#include<bits/basic_ios.h>
#include<bits/basic_string.h>
#include<bits/basic_string.tcc>
#include<bits/c++config.h>
#include<bits/char_traits.h>
#include<bits/cpp_type_traits.h>
#include<bits/cxxabi_forced.h>
#include<bits/ios_base.h>
#include<bits/locale_classes.h>
#include<bits/localefwd.h>
#include<bits/ostream_insert.h>
#include<bits/postypes.h>
#include<bits/range_access.h>
#include<bits/stl_algobase.h>
#include<bits/stl_function.h>
#include<bits/stl_iterator.h>
#include<bits/stl_iterator_base_funcs.h>
#include<bits/stl_iterator_base_types.h>
#include<bits/stringfwd.h>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwchar>
#include<cwctype>
#include<debug/debug.h>
#include<deque>
#include<exception>
#include<ext/atomicity.h>
#include<ext/numeric_traits.h>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<math.h>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<utility>
#include<valarray>
#include<vector>
using namespace std;
int c[5][5],f;
int main()
{
	cin>>c[0][0]>>c[0][1]>>c[0][2];
	cin>>c[1][0]>>c[1][1]>>c[1][2];
	cin>>c[2][0]>>c[2][1]>>c[2][2];
	for (int i=-100;i<=100;i++){
		int b1=c[0][0]-i,b2=c[0][1]-i,b3=c[0][2]-i;
		if (c[1][0]-b1==c[1][1]-b2)
			if (c[1][2]-b3==c[1][1]-b2)
				if (c[2][2]-b3==c[2][1]-b2)
					if (c[2][2]-b3==c[2][1]-b2)
						f=1;
	}
	if (f==0)
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}