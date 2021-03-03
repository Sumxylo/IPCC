#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
bool check(int n,int U,int R,int D,int L,int UR,int RD,int DL,int LU){
	if(U>=LU+UR&&U-LU-UR<=n-2)
		if(R>=UR+RD&&R-UR-RD<=n-2)
			if(D>=RD+DL&&D-RD-DL<=n-2)
				if(L>=DL+LU&&L-DL-LU<=n-2)
					return true;
	return false;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		int n,U,R,D,L;cin>>n>>U>>R>>D>>L;
		bool flag=false;
		for(int UR=0;UR<2;++UR)
			for(int RD=0;RD<2;++RD)
				for(int DL=0;DL<2;++DL)
					for(int LU=0;LU<2;++LU)
						if(check(n,U,R,D,L,UR,RD,DL,LU)){
							flag=true;
							break;
						}
		puts(flag?"YES":"NO");
	}
	return 0;
}