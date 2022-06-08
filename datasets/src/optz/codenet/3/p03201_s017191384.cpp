#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
//const int MOD=998244353;

const double PI=3.14159265359;

class Edge{
    public:
    int cap,flow,dest;
    bool inGraph;
    Edge *flEdgePair, *resEdgePair;
    Edge(int _dest, int _cap, bool ing, int _flow=0):dest(_dest),inGraph(ing),
    cap(_cap), flow(_flow){}
    
    void addFlow(int fl){
        cap-=fl;
        resEdgePair->cap+=fl;
        if(inGraph) flEdgePair->flow+=fl;
        else flEdgePair->flow-=fl;
    }
};

class Dinic{
    public:
    vector<vector<Edge*>> flow, res;
    vector<int> dists, preds;
    
    int S,n,T;
    Dinic(vector<vector<pair<int,int>>>& net):S(0), n(net.size()), T(n-1){
        flow.resize(n);
        res.resize(n);
        dists.resize(n);
        preds.resize(n);
		fill(preds.begin(), preds.end(),-1);
        
        for(int i=0; i<n; i++){
            for(auto p:net[i]){
                Edge* e1=new Edge(p.first, p.second, true);
                Edge* e2=new Edge(i, 0, false);
                Edge* e3=new Edge(p.first, p.second, true);
                
                e1->flEdgePair=e3;
                e2->flEdgePair=e3;
                e1->resEdgePair=e2;
                e2->resEdgePair=e1;
                flow[i].push_back(e3);
                res[i].push_back(e1);
                res[p.first].push_back(e2);
            }
        }
    }
    bool bfs(){
        fill(dists.begin(), dists.end(),-1);
        queue<int> q;
        q.push(S);
        dists[S]=0;
        while(q.size()){
            int cur=q.front();
            q.pop();
            for(auto e:res[cur]){
                if(e->cap && dists[e->dest]==-1){
                    dists[e->dest]=dists[cur]+1;
                    q.push(e->dest);
                }
            }
        }
        return dists[T]!=-1;
    }
    
    void dfs(){
        vector<int> ep(n);
        vector<bool> dead(n);
        while(!dead[S]){
            //vector<int> preds(n,-1);
            stack<int> st;
            st.push(0);
            while(st.size()){
                int cur=st.top();
                //cout<<cur<<endl;
                if(cur==T) break;
                while(ep[cur]<res[cur].size() && (dead[res[cur][ep[cur]]->dest] ||
                dists[res[cur][ep[cur]]->dest]!=dists[cur]+1 || 
                res[cur][ep[cur]]->cap==0)){
                    ep[cur]++;
                }
                if(ep[cur]==res[cur].size()){
                    dead[cur]=true;
                    st.pop();
                }
                else{
                    preds[res[cur][ep[cur]]->dest]=cur;
                    st.push(res[cur][ep[cur]]->dest);
                }
            }
            if(st.size() && st.top()==T){
                //cout<<st.size()<<endl;
                int flVal=1e9;
                int cur=T;
                while(cur!=S){
                    //cout<<cur<<endl;
                    cur=preds[cur];
                    flVal=min(flVal,res[cur][ep[cur]]->cap);
                }
                cur=T;
                while(cur!=S){
                    cur=preds[cur];
                    res[cur][ep[cur]]->addFlow(flVal);
                }
            }
            else{
                dead[S]=true;
            }
            
        }
        
    }
    
    vector<vector<Edge*>> maxflow(){
        //bfs();
        //dfs();
        while(bfs()){
            dfs();
        }
        return flow;
    }
    
    
};



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    vector<int> v(n);
    
    for(int& i:v){
        cin>>i;
    }
    
    vector<pair<int,int>> vp;
    
    sort(v.begin(),v.end());
    
    for(int i=0; i<n; i++){
        if(!vp.size() || vp.back().first!=v[i]){
            vp.push_back({v[i], 1});
        }
        else{
            vp.back().second++;
        }
    }
    
    //cout<<vp.size()<<'\n';
    
    int n2=vp.size();
    
    int netsz=2*vp.size()+2;
    
    vector<vector<pair<int,int>>> net(netsz);
    
    for(int i=0; i<vp.size(); i++){
        net[0].push_back({i+1,vp[i].second});
        net[n2+i+1].push_back({netsz-1,vp[i].second});
        
        
        for(int j=0; j<=30; j++){
            int goal=(1<<j)-vp[i].first;
            pair<int,int> pg={goal,0};
            auto it=lower_bound(vp.begin(),vp.end(),pg);
            if(it==vp.end()) continue;
            int k=it-vp.begin();
            if(it->first==goal){
                
                if(goal==vp[i].first){
                    if(it->second>1){
                        net[i+1].push_back({n2+k+1,(it->second)-(it->second)%2});
                    }
                }
                
                else{
                    net[i+1].push_back({n2+k+1,it->second});
                }
                
            }
            
            
        }
        
        
    }
    
    /*
    for(int i=0; i<netsz; i++){
        cout<<i<<":\n";
        for(auto p:net[i]){
            cout<<p.first<<','<<p.second<<'\n';
        }
    }
    */
    
    Dinic din(net);
    
    
    auto mf=din.maxflow();
    
    int ans=0;
    
    for(auto e:mf[0]){
        ans+=e->flow;
    }
    
    cout<<ans/2;
    
    
    return 0;
}
