#include<cstdio>
int a[100005];
int main(){
	//freopen("in","r",stdin);
	int t,n,m;scanf("%d",&t);
	double pp;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int sp;
		for(sp=n;a[sp]==sp&&sp>0;sp--);
		int r;double p;
		pp=1.0;
		while(m--){
			scanf("%d%lf",&r,&p);
			if(r>=sp)
				pp*=1.0-p;
		}
		if(sp==0)
			puts("1.000000");
		else
			printf("%.6lf\n",1-pp);
	}
	return 0;
}