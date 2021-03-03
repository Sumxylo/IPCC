#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
bool check(string s,int a,int b,int c){
	int strl=s.length();
	int l=0;
	for(int i=0;i<strl;++i){
		if(s[i]=='A')
			l+=a;
		elif(s[i]=='B')
			l+=b;
		else
			l+=c;
		if(l<0)
			return false;
	}
	return l==0;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;scanf("%d",&t);
	while(t--){
		string s;cin>>s;
		bool flag=false;
		for(int A=-1;A<2;A+=2)
			for(int B=-1;B<2;B+=2)
				for(int C=-1;C<2;C+=2)
					if(check(s,A,B,C)){
						flag=true;
						break;
					}
		puts(flag?"YES":"NO");
	}
	return 0;
}