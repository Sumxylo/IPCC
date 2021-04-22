#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int a[2003];
int tb[2003][2003];
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i){
			int xorsum=0;
			for(int j=i;j<=n;++j){
				xorsum^=a[j];
				tb[i][j]=xorsum;
			}
		}
		bool flag=false;
		for(int i=1;i<n;++i)
			if(tb[1][i]==tb[i+1][n]){
				flag=true;
				break;
			}
		if(!flag)
			for(int i=1;i<n-1;++i)
				for(int j=i+1;j<n;++j)
					if(tb[1][i]==tb[i+1][j]&&tb[1][i]==tb[j+1][n]){
						flag=true;
						break;
					}
		puts(flag?"YES":"NO");
	}
	return 0;
}