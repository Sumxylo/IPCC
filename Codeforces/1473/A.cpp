#include<bits/stdc++.h>
#define elif else if
using namespace std;
int a[105];
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		int n,d;scanf("%d%d",&n,&d);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		int max=0,min1=101,min2=101;
		for(int i=0;i<n;++i){
			if(a[i]>max)
				max=a[i];
			if(a[i]<min1){
				min2=min1;
				min1=a[i];
			}elif(a[i]<min2)
				min2=a[i];
		}
		if(max<=d||min1+min2<=d)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}