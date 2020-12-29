#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n,m;
		int an[101]={0},am[101]={0},bn[101]={0},bm[101]={0};
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&an[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;++i)
			scanf("%d",&am[i]);
		for(int i=1;i<=n;++i)
			bn[i]=bn[i-1]+an[i];
		for(int i=1;i<=m;++i)
			bm[i]=bm[i-1]+am[i];
		int minv=0x80000000;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				if(minv<bn[i]+bm[j])
					minv=bn[i]+bm[j];
		printf("%d\n",minv);
	}
	return 0;
}