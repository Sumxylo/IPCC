#include<bits/stdc++.h>
using namespace std;
bool check(long long n){
	long long i=n;
	while(i){
		if(i%10!=0)
			if(n%(i%10)!=0)
				return false;
		i/=10;
	}
	return true;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		long long n;scanf("%lld",&n);
		for(long long i=n;i<n+2520;++i)
			if(check(i)){
				printf("%lld\n",i);
				break;
			}
	}
	return 0;
}