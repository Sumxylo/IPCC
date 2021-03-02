#include<bits/stdc++.h>
#define elif else if
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		if(n==1){
			puts("9");
			continue;
		}
		printf("98");
		for(int i=9;i<n+7;++i)
			printf("%d",(i%10));
		puts("");
	}
	return 0;
}