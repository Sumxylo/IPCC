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
		int n;cin>>n;
		vector<int> x,y;
		for(int i=0;i<n*2;++i){
			int X,Y;
			scanf("%d%d",&X,&Y);
			if(X==0)
				y.push_back(abs(Y));
			else
				x.push_back(abs(X));
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		double ans=0;
		for(int i=0;i<n;++i)
			ans+=sqrt(pow(x[i],2)+pow(y[i],2));
		printf("%.10lf\n",ans);
	}
	return 0;
}