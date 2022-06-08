#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>

using int64=long long;
using uchar=unsigned char;

constexpr int maxn(200000);

template<class _Tpx,class _Tpy>
	inline _Tpx Min(const _Tpx&x,const _Tpy&y)
		{return x<y?x:y;}

namespace IOManager{
	constexpr int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,stdin),ibuf==tbuf)?EOF:*ibuf++;}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0u;char c=gc();
				for(;c<48;c=gc());
				for(;c>47;c=gc())
					s=(_Tp)(s*10u+c-48u);
				return s;
			}
	};
}IOManager::IOManager io;

template<int vsz,int esz>
	struct NetWork{
		static constexpr int inf=2147483647;


		struct Edge{
			int v,c;Edge*las,*rev;
			inline Edge* init(const int&to,const int&cap,Edge*const&ls,Edge*const&re)
				{return v=to,c=cap,las=ls,rev=re,this;}
		}*las[vsz+1],*cur[vsz+1];

		Edge pool[esz<<1],*alc;
		inline void AddEdge(const int&u,const int&v,const int&c){
			las[u]=alc->init(v,c,las[u],alc+1);++alc;
			las[v]=alc->init(u,0,las[v],alc-1);++alc;
		}

		int n,src,ter;
		/*source->terminal*/
		int dis[vsz+1],
			gap[vsz+1];

		inline void clr(const int&nn){
			alc=pool;n=nn;
			memset(las,0,sizeof las);
		}

		int calc(const int&u,const int&maxflow){
			if(u==ter)
				return maxflow;
			int s=0;
			for(Edge*&o=cur[u];o;o=o->las)
				if(o->c&&dis[u]==dis[o->v]+1){
					int t=calc(o->v,Min(maxflow-s,o->c));
					o->c-=t;o->rev->c+=t;
					if((s+=t)==maxflow)
						return s;
				}
			if(!--gap[dis[u]])
				dis[src]=n;
			return++gap[++dis[u]],cur[u]=las[u],s;
		}

		inline int64 flow(const int&s,const int&t){
			src=s;ter=t;
			memset(gap+1,0,n<<2);
			memset(dis+1,0,n<<2);
			std::copy(las+1,las+n+1,cur+1);

			int64 ans=0;
			for(gap[0]=n;dis[src]<n;)
				ans+=calc(src,inf);
			return ans;
		}
	};

NetWork<maxn+maxn+10,maxn*10>net;

int a[maxn+1];

std::map<int,int>idx,cnt;

int main(){
	const int n=io;int id=0;
	for(int i=1;i<=n;++i)
		if(idx.count(a[i]=io))
			++cnt[a[i]];
		else
			idx[a[i]]=++id,cnt[a[i]]=1;

	const int S=id+id+1,T=S+1;
	net.clr(T);

	for(auto&num:idx){
		const int v=num.first,cv=cnt[v];
		net.AddEdge(S,num.second,cv);
		net.AddEdge(num.second+id,T,cv);
		int t=0;
		for(;(1<<t)<=v;++t);
		for(;t!=31;++t)
			if(idx.count((1<<t)-v))
				net.AddEdge(num.second,idx[(1<<t)-v]+id,Min(cv,cnt[(1<<t)-v]));
	}

	printf("%d",net.flow(S,T)>>1);

	return 0;
}
