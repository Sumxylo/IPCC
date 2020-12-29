#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	char s[101];
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		if(len&1){
			puts("NO");
			continue;
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=0;i<len;++i){
			if(s[i]=='(')
				++cnt1;
			if(s[i]==')')
				++cnt2;
			if(s[i]=='?')
				++cnt3;
			if(cnt1+cnt3<cnt2)
				break;
		}
		if(cnt1+cnt3<cnt2){
			puts("NO");
			continue;
		}
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=len-1;i>=0;--i){
			if(s[i]=='(')
				++cnt1;
			if(s[i]==')')
				++cnt2;
			if(s[i]=='?')
				++cnt3;
			if(cnt2+cnt3<cnt1)
				break;
		}
		if(cnt2+cnt3<cnt1){
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}