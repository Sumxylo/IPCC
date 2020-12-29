#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int nn=n,m=0;
		for(int i=n-1;i>2;--i){
			if(nn/i+(nn%i>0)>=i)
				nn=nn/i+(nn%i>0),++m;
			m++;
		}
		while(nn!=1){
			nn=nn/2+(nn%2>0);
			m++;
		}
		printf("%d\n",m);
		nn=n;
		for(int i=n-1;i>2;--i){
			if(nn/i+(nn%i>0)>=i)
				nn=nn/i+(nn%i>0),printf("%d %d\n",n,i);
			printf("%d %d\n",i,n);
		}
		while(nn!=1){
			nn=nn/2+(nn%2>0);
			printf("%d %d\n",n,2);
		}
	}
	return 0;
}