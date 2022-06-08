    #include<bits/stdc++.h>
    using namespace std;
    const int N=1e5+11;
    int n;
    multiset<int> s;
    multiset<int>::iterator it;
    int main(){
    #ifdef flukehn
    	freopen("a.in","r",stdin);
    #endif
    	cin>>n;
    	int i,x;
    	for(i=0;i<n;++i){
    		scanf("%d",&x);
    		s.insert(x);
    	}
    	int ans=0,j,y;
    	for(;!s.empty();){
    		it=s.end();
    		--it;
    		x=*it;
    		s.erase(it);
    		for(j=30;j;--j){
    			y=(1<<j)-x;
    			it=s.lower_bound(y);
    			if(it==s.end()||*it!=y)continue;
    			s.erase(it);
    			++ans;
    			break;
    		}
    	}
    	cout<<ans<<endl;
    }