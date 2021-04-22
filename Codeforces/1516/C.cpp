#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int n,a[102];
int sa,dp[102][200005];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool r_dfs(int p,int sum){
	if(p>n){
		if(sum==sa-sum)
			return false;
		return true;
	}
	if(dp[p][sum])
		return dp[p][sum]==1?true:false;
	if(!r_dfs(p+1,sum+a[p])){
		dp[p][sum]=-1;
		return false;
	}
	if(!r_dfs(p+1,sum)){
		dp[p][sum]=-1;
		return false;
	}
	dp[p][sum]=1;
	return true;
}
int main(){
	cin>>n;
	int gcds=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		gcds=gcd(gcds,a[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]/=gcds;
		sa+=a[i];
	}
	bool ans=r_dfs(1,0);
	if(ans)
		puts("0");
	else
		for(int i=1;i<=n;++i)
			if(a[i]&1){
				printf("1\n%d\n",i);
				break;
			}
	return 0;
}