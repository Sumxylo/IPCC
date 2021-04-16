#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
const int N=100005;
int n,m;
int w[N],c[N];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&c[i]);
	sort(w+1,w+n+1);
	sort(c+1,c+m+1);
	int wi=1,ci=1;
	while(wi<=n&&ci<=m){
		if(w[wi]>=c[ci])
			++wi,++ci;
		else
			++wi;
	}
	printf("%d\n",ci-1);
	return 0;
}