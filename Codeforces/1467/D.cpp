#include<bits/stdc++.h>
#define elif else if
using namespace std;
const int MOD=1000000007;
int n,k,q;
int a[5005];
int dp1[5005][5005];
int dp2[5005];
inline int mod(long long a){if(a<0)return a+MOD;return a%MOD;}
void init(){
	for(int i=1;i<=n;++i)
		dp1[0][i]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			dp1[i][j]=mod(dp1[i-1][j-1]+dp1[i-1][j+1]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=k;++j)
			dp2[i]=mod(dp2[i]+1ll*dp1[j][i]*dp1[k-j][i]);
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d%d",&n,&k,&q);
	init();
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=1;i<=n;++i)
		sum=mod(sum+1ll*dp2[i]*a[i]);
	while(q--){
		int i,x;scanf("%d%d",&i,&x);
		sum=mod(sum+1ll*dp2[i]*mod(x-a[i]));
		a[i]=x;
		printf("%d\n",sum);
	}
	return 0;
}