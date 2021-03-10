/*
Dinic最大流：求指定源点到汇点的最大流
注意：先用Addedge建好图，设置全局变量S、T的值分别为源、汇点的点编号，再调用Dinic函数求解。多次使用该算法时要对全局变量重新初始化
时间：最大O(N^2*M)，实际一般远低于上界，二分图匹配时O(N^0.5*M)
空间：O(N^2)
全局变量：有
STL：有
*/
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;
const int N=505;//N确定数组大小，使用时应改为比点数稍大
const int INF=0x3f3f3f3f;
struct Edge{
    int u,v,cap;
    Edge(){}
    Edge(int u,int v,int cap):u(u),v(v),cap(cap){}
}edge[N*N];
vector<int> G[N];
vector<int>::iterator cur[N];
int S,T,dis[N],tot;//S、T分别为源、汇点的编号
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
    for(vector<int>::iterator i=cur[u];i!=G[u].end();++i){
        cur[u]=i;
        Edge &e=edge[*i];
        if(dis[e.v]==dis[u]+1&&e.cap>0){
            int flow=DFS(e.v,min(e.cap,maxflow));
            if(flow){
                e.cap-=flow;
                edge[*i^1].cap+=flow;
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
        for(int i=0;i<N;++i)
            cur[i]=G[i].begin();
        while(flow=DFS(S,INF))
			ans+=flow;
    }
    return ans;
}