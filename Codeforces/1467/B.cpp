#include<bits/stdc++.h>
#define elif else if
using namespace std;
int a[300005],n;
bool ishv(int x){
	if(x==0||x==n-1)
		return false;
	return (a[x]>a[x-1]&&a[x]>a[x+1])||(a[x]<a[x-1]&&a[x]<a[x+1]);
}
inline void updmin(int &a,int b){if(a>b)a=b;}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		if(n<=3){
			puts("0");
			continue;
		}
		int hv=0,ans;
		for(int i=1;i<n-1;++i)
			hv+=ishv(i);
		ans=hv;
		for(int i=1;i<n-1;++i)
			if(ishv(i)){
				int t=a[i],o=ishv(i-1)+ishv(i)+ishv(i+1);
				a[i]=a[i-1];
				updmin(ans,hv-o+ishv(i-1)+ishv(i)+ishv(i+1));
				a[i]=a[i+1];
				updmin(ans,hv-o+ishv(i-1)+ishv(i)+ishv(i+1));
				a[i]=t;
			}
		printf("%d\n",ans);
	}
	return 0;
}