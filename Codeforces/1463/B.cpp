#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int a[51];
		long long sum[2]={0};
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			sum[i&1]+=a[i];
		for(int i=1;i<=n;++i)
			printf("%d ",(i&1)==(sum[0]<sum[1])?a[i]:1);
		puts("");
	}
	return 0;
}