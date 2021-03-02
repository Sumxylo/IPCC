#include<bits/stdc++.h>
#define elif else if
using namespace std;
bool ans[2021000];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	for(int i=0;i<500;++i)
		for(int j=0;j<500;++j)
			ans[i*2020+j*2021]=true;
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		puts(ans[n]?"YES":"NO");
	}
	return 0;
}