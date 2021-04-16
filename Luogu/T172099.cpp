#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int n,m,p;
int cd[3][51]={0},pld[3]={0};
pair<int,int> mini(int p,pair<int,int> lp){
	int b1=m+1,b2=n+1;
	for(int i=lp.first+1;i<=m;++i)
		if(cd[p][i]>=lp.second)
			return make_pair(i,lp.second);
	for(int i=lp.second+1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(cd[p][j]>=i)
				return make_pair(j,i);
	return make_pair(0,1);
}
void play(int p,pair<int,int> lp){
	cd[p][lp.first]-=lp.second;
	pld[p]+=lp.second;/*
	printf("%d [",p);
	for(int i=0;i<lp.second;++i)
		printf("%d ",lp.first);
	puts("]");*/
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<3;++i)
		for(int j=0;j<n;++j){
			cin>>p;
			cd[i][p]++;
		}
	p=0;
	int b3=0;
	pair<int,int> lp=make_pair(0,1);
	while(1){
		pair<int,int> pl=mini(p,lp);
		if(pl==make_pair(0,1)){
			b3++;p=(p+1)%3;
			if(b3==2){
				b3=0;
				lp=pl;
			}
		}else{
			play(p,pl);
			if(pld[p]==n){
				printf("%d\n",p+1);
				break;
			}
			b3=0;
			p=(p+1)%3;
			lp=pl;
		}
	}
	return 0;
}