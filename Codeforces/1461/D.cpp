#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int t,n,q;
int a[100005];
long long b[100005];
set<int> ans;
void dfs(int l,int r){
	if(b[r]-b[l-1]<=1000000000)
		ans.insert(b[r]-b[l-1]);
	int *pmid=upper_bound(a+l,a+r+1,(a[l]+a[r])/2);
	if(pmid-a>r)
		return;
	dfs(l,pmid-a-1);
	dfs(pmid-a,r);
}
int main(){
	//freopen("in","r",stdin);
	int x;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			b[i]=b[i-1]+a[i];
		dfs(1,n);
		for(int i=0;i<q;++i){
			scanf("%d",&x);
			if(ans.find(x)!=ans.end())
				puts("Yes");
			else
				puts("No");
		}
		ans.clear();
	}
	return 0;
}