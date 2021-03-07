#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T;cin>>T;
	while(T--){
		int n,k;cin>>n>>k;
		printf("%d\n",n-k+k/2);
		for(int i=(k+1)/2;i<k;++i)
			printf("%d ",i);
		for(int i=k+1;i<=n;++i)
			printf("%d%c",i,i==n?'\n':' ');
	}
	return 0;
}