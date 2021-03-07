#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
void nextmin(int &H,int &M,int h,int m){
	if(++M>=m){
		if(++H>=h)
			H=0;
		M=0;
	}
}
int rever(int N){
	int a=N/10,b=N%10;
	int A,B;
	switch(a){
		case 0:B=0;break;
		case 1:B=1;break;
		case 2:B=5;break;
		case 3:return -1;break;
		case 4:return -1;break;
		case 5:B=2;break;
		case 6:return -1;break;
		case 7:return -1;break;
		case 8:B=8;break;
		case 9:return -1;break;
	}
	switch(b){
		case 0:A=0;break;
		case 1:A=1;break;
		case 2:A=5;break;
		case 3:return -1;break;
		case 4:return -1;break;
		case 5:A=2;break;
		case 6:return -1;break;
		case 7:return -1;break;
		case 8:A=8;break;
		case 9:return -1;break;
	}
	return A*10+B;
}
bool work(int H,int M,int h,int m){
	int _H=rever(M),_M=rever(H);
	return _H>=0&&_H<h&&_M>=0&&_M<m;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T;cin>>T;
	while(T--){
		int h,m,H,M;
		scanf("%d%d",&h,&m);
		scanf("%d:%d",&H,&M);
		while(!work(H,M,h,m))
			nextmin(H,M,h,m);
		printf("%02d:%02d\n",H,M);
	}
	return 0;
}