#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int n,k;
int a[6],b[6];
int p[6],u[6];
int ans[6]={99,99,99,99,99,99};
void check(){
	for(int i=0;i<k;++i)
		if(b[i]>a[p[i]])
			return;
	for(int i=0;i<k;++i){
		if(ans[i]<p[i])
			return;
		if(ans[i]>p[i])
			break;
	}
	for(int i=0;i<k;++i)
		ans[i]=p[i];
}
void dfs(int d){
	if(d==k){
		check();
		return;
	}
	for(int i=0;i<n;++i)
		if(!u[i]){
			u[i]=1;
			p[d]=i;
			dfs(d+1);
			u[i]=0;
		}
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<k;++i)
		cin>>b[i];
	dfs(0);
	if(ans[0]==99)
		puts("-1");
	else
		for(int i=0;i<k;++i)
			printf("%d%c",ans[i]+1,i==k-1?'\n':' ');
	return 0;
}