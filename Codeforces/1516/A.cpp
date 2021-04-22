#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int a[102];
int main(){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<n;++i)
			if(a[i]>=k){
				a[n]+=k;
				a[i]-=k;
				break;
			}else{
				a[n]+=a[i];
				k-=a[i];
				a[i]=0;
			}
		for(int i=1;i<=n;++i)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}