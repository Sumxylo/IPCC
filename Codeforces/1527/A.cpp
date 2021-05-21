#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int getL(int n){
	int ans=0;
	while(n){
		n>>=1;
		ans++;
	}
	return ans;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int log2n=getL(n);
		int ans=0;
		for(int i=0;i<log2n;++i){
			if((n>>i)&1){
				int thisl=n%(1<<(i+1))-(1<<i)+1;
				if(ans<thisl)
					ans=thisl;
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}