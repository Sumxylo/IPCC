#include<cstdio>
int t,n,m;
int a[510][510],b[510][510];
int cnt;
void work(int x,int y){
	for(int i=0;i<=n-x;i++){
		if(y-i<1||y+i>m)
			break;
		if(b[x+i][y+i]-b[x+i][y-i-1]!=2*i+1)
			break;
		cnt++;
	}
}
int getvh(){
	char c;
	for(c=getchar();c!='.'&&c!='*';c=getchar());
	return c=='.'?0:1;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&t);
	while(t--){
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=getvh();
				b[i][j]=b[i][j-1]+a[i][j];
			}
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				work(i,j);
		printf("%d\n",cnt);
	}
	return 0;
}