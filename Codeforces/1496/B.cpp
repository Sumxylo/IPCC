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
		int x,mex,max;
		set<int> a;
		vector<int> b;
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			a.insert(x);
			b.push_back(x);
		}
		sort(b.begin(),b.end());
		max=b[n-1];
		bool flag=true;
		for(int i=0;i<n;++i)
			if(b[i]!=i){
				mex=i;
				flag=false;
				break;
			}
		if(k==0){
			printf("%d\n",a.size());
			continue;
		}
		if(flag){
			printf("%d\n",a.size()+k);
			continue;
		}
		if(a.find((mex+max)/2+(mex+max)%2)!=a.end())
			printf("%d\n",n);
		else
			printf("%d\n",n+1);
	}
	return 0;
}