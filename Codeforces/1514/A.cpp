#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int a[102];
bool tps[10004];
void init(){
	for(int i=1;i*i<=10000;++i)
		tps[i*i]=true;
}
int main(){
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		bool flag=false;
		for(int i=1;i<=n;++i)
			if(!tps[a[i]]){
				flag=true;
				break;
			}
		puts(flag?"YES":"NO");
	}
	return 0;
}