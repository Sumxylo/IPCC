#include<bits/stdc++.h>
using namespace std;
int r[1005],b[1005];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%1d",&r[i]);
		for(int i=1;i<=n;++i)
			scanf("%1d",&b[i]);
		int rw=0,dw=0,bw=0;
		for(int i=1;i<=n;++i)
			if(r[i]>b[i])
				rw++;
			else if(r[i]<b[i])
				bw++;
			else
				dw++;
		if(rw>bw)
			puts("RED");
		else if(rw<bw)
			puts("BLUE");
		else
			puts("EQUAL");
	}
	return 0;
}