#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;cin>>n;
	vector<int> ans;
	int procans=1;
	for(int i=1;i<=n-2;++i)
		if(gcd(i,n)==1)
			ans.push_back(i),procans=procans*1ll*i%n;
	if(procans*1ll*(n-1)%n==1)
		ans.push_back(n-1);
	printf("%ld\n",ans.size());
	for(vector<int>::iterator i=ans.begin();i!=ans.end();++i)
		printf("%d ",*i);
	return 0;
}