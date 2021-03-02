#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int h[105];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		ll sum=0;
		bool flag=false;
		for(int i=1;i<=n;++i){
			scanf("%d",&h[i]);
			if(flag)
				continue;
			sum+=h[i];
			if(sum<i-1)
				flag=true;
			sum-=i-1;
		}
		puts(flag?"NO":"YES");
	}
	return 0;
}