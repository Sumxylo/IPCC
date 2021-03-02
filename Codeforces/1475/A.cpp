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
		long long n;scanf("%lld",&n);
		while(n%2==0)
			n/=2;
		puts(n==1?"NO":"YES");
	}
	return 0;
}