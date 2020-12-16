#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int a[3005],n;
set<int> factor;
bool test(int s){
	int temp=0;
	for(int i=1;i<=n;++i){
		temp+=a[i];
		if(temp>s)
			return false;
		if(temp==s)
			temp-=s;
	}
	return true;
}
int main(){
	int t,sum,maxx;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum=0;maxx=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
			if(maxx<a[i])maxx=a[i];
		}
		for(int i=1;i*i<=sum;++i)
			if(sum%i==0){
				if(i>=maxx)factor.insert(i);
				if(sum/i>=maxx)factor.insert(sum/i);
			}
		for(set<int>::iterator i=factor.begin();i!=factor.end();++i)
			if(test(*i)){
				printf("%d\n",n-sum/(*i));
				break;
			}
		factor.clear();
	}
	return 0;
}