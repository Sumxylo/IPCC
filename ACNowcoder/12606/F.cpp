#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int w[20004];
ll psum[20004];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int m,x;cin>>m;
	for(int i=1;i<=m;++i){
		scanf("%d",&x);
		w[x]++;
	}
	for(int i=1;i<=20000;++i)
		psum[i]=psum[i-1]+1ll*i*w[i];
	for(int i=1;i<=20000;++i)
		if(psum[i-1]==psum[20000]-psum[i]){
			printf("%d\n",i);
			break;
		}
	return 0;
}