#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		string s;cin>>s;
		if(k==0){
			puts("YES");
			continue;
		}
		if(k>(n-1)/2){
			puts("NO");
			continue;
		}
		bool flag=true;
		for(int i=0;i<k;++i)
			if(s[i]!=s[n-i-1]){
				flag=false;
				break;
			}
		puts(flag?"YES":"NO");
	}
	return 0;
}