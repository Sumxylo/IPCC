#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int N;
string s[502];
vector<int> e[502];
vector<int> col[3];
bool added[502][502];
int cl[502];
bool cgb(int x,int y){
	int l=s[x].length(),c=0;
	for(int i=0;i<l;++i)
		if(s[x][i]!=s[y][i])
			++c;
	return c==2;
}
void adde(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
struct Edge{
    int u,v,cap;
    Edge(){}
    Edge(int u,int v,int cap):u(u),v(v),cap(cap){}
}edge[300005];
vector<int> G[502];
int S,T,cur[502],dis[502],tot;
void Addedge(int u,int v,int cap) {
    G[u].push_back(tot);
    edge[tot++]=Edge(u,v,cap);
    G[v].push_back(tot);
    edge[tot++]=Edge(v,u,0);
}
int BFS(){
    queue<int> que;
    while(!que.empty())
		que.pop();
    memset(dis,INF,sizeof(dis));
    que.push(S);
    dis[S]=0;
    while(!que.empty()){
        int u=que.front();que.pop();
        for(vector<int>::iterator i=G[u].begin();i!=G[u].end();++i){
            Edge &e=edge[*i];
            if(dis[e.v]==INF&&e.cap>0){
                dis[e.v]=dis[u]+1;
                que.push(e.v);
            }
        }
    }
    return dis[T]!=INF;
}
int DFS(int u,int maxflow){
    if(u==T)
		return maxflow;
    for(int i=cur[u];i<G[u].size();i++){
        cur[u]=i;
        Edge &e=edge[G[u][i]];
        if(dis[e.v]==dis[u]+1&&e.cap>0){
            int flow=DFS(e.v,min(e.cap,maxflow));
            if(flow){
                e.cap-=flow;
                edge[G[u][i]^1].cap+=flow;
                return flow;
            }
        }
    }
    return 0;
}
int Dinic(){
    int ans=0;
    while(BFS()){
        int flow;
        memset(cur,0,sizeof(cur));
        while(flow=DFS(S,INF))
			ans+=flow;
    }
    return ans;
}
void color(int p){
	queue<int> q;
	cl[p]=1;q.push(p);col[1].push_back(p);
	while(!q.empty()){
		int qf=q.front();q.pop();
		for(vector<int>::iterator i=e[qf].begin();i!=e[qf].end();++i){
			if(!added[qf][*i]){
				if(cl[qf]==1)
					Addedge(qf,*i,1);
				else
					Addedge(*i,qf,1);
				added[qf][*i]=added[*i][qf]=true;
			}
			if(cl[*i]==0){
				col[cl[*i]=3-cl[qf]].push_back(*i);
				q.push(*i);
			}
		}
	}
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>s[i];
	for(int i=1;i<N;++i)
		for(int j=i+1;j<=N;++j)
			if(cgb(i,j))
				adde(i,j);
	int ans=0;
	for(int i=1;i<=N;++i)
		if(cl[i]==0)
			color(i);
	for(vector<int>::iterator i=col[1].begin();i!=col[1].end();++i)
		Addedge(0,*i,1);
	for(vector<int>::iterator i=col[2].begin();i!=col[2].end();++i)
		Addedge(*i,501,1);
	S=0,T=501;
	printf("%d\n",N-Dinic());
	return 0;
}