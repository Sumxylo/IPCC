#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int p[100005];
vector<int> po[100005];
set<int> len;
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n;cin>>n;
	for(int i=0;i<n;++i)
		scanf("%d",&p[i]);
	bool up=p[1]>p[0];
	int pk=0,cnt=2;
	for(int i=2;i<n;++i){
		if(up){
			if(p[i]>p[i-1])
				cnt++;
			else{
				po[cnt].push_back(i-1);
				len.insert(cnt);
				cnt=2;pk=i-1;up=false;
			}
		}else{
			if(p[i]<p[i-1])
				cnt++;
			else{
				po[cnt].push_back(pk);
				len.insert(cnt);
				cnt=2;up=true;
			}
		}
	}
	if(up){
		po[cnt].push_back(n-1);
		len.insert(cnt);
	}else{
		po[cnt].push_back(pk);
		len.insert(cnt);
	}
	int ml=*len.rbegin();
	if(ml%2==0)
		puts("0");
	else{
		if(po[ml].size()!=2)
			puts("0");
		else{
			if(po[ml][0]==po[ml][1])
				puts(po[ml][0]?"1":"0");
			else
				puts("0");
		}
	}
	return 0;
}