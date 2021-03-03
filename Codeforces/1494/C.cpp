#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int P=1000000009;
vector<int> a1,a2,b1,b2;
int work(vector<int> &a,vector<int> &b){
	a.push_back(P);
	vector<int>::iterator A=a.begin(),B=b.begin();
	int cntx=0,ans=0;
	while(B!=b.end()){
		if(*A<*B){
			cntx++;
			A++;
		}elif(*A==*B){
			ans++;cntx++;
			A++;B++;
		}else{
			vector<int>::iterator pp=upper_bound(b.begin(),b.end(),*B-cntx);
			ans=max(ans,(int)(B-pp)+1);
			B++;
		}
	}
	return ans;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int x;
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			if(x<0)
				a1.push_back(-x);
			else
				a2.push_back(x);
		}
		for(int i=0;i<m;++i){
			scanf("%d",&x);
			if(x<0)
				b1.push_back(-x);
			else
				b2.push_back(x);
		}
		reverse(a1.begin(),a1.end());
		reverse(b1.begin(),b1.end());
		printf("%d\n",work(a1,b1)+work(a2,b2));
		a1.clear();a2.clear();b1.clear();b2.clear();
	}
	return 0;
}