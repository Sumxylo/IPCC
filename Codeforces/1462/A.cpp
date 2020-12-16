#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("in","r",stdin);
	int t,n;
	int b[301];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		for(int x=0,y=n-1;x<=y;){
			if(x<=y){printf("%d ",b[x]);++x;}
			if(x<=y){printf("%d ",b[y]);--y;}
		}
	}
	return 0;
}