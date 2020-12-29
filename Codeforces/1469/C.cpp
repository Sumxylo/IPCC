#include<bits/stdc++.h>
using namespace std;
int h[200005];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n,k;scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",&h[i]);
		int ue=h[1],shita=h[1];
		bool ok=true;
		for(int i=2;i<=n;++i){
			ue=min(h[i]+k-1,ue+k-1);
			shita=max(h[i],shita-k+1);
			if(ue<shita){
				ok=false;
				break;
			}
		}
		if(ok)
			if(h[n]<shita||h[n]>ue)
				ok=false;
		puts(ok?"YES":"NO");
	}
	return 0;
}