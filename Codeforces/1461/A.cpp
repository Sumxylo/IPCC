#include<cstdio>
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		int ta[3]={'a','b','c'};
		for(int i=0;i<n;++i)
			putchar(ta[i%3]);
		puts("");
	}
	return 0;
}