#include<bits/stdc++.h>
#define elif else if
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int q;scanf("%d",&q);
	while(q--){
		char s[25],t[25];
		scanf("%s",s);
		scanf("%s",t);
		int ls=strlen(s),lt=strlen(t);
		int len=lcm(ls,lt);
		bool flag=true;
		for(int i=0;i<len;++i)
			if(s[i%ls]!=t[i%lt]){
				flag=false;
				break;
			}
		if(flag)
			for(int i=0;i<len;++i)
				putchar(s[i%ls]);
		else
			printf("-1");
		puts("");
	}
	return 0;
}