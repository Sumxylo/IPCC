#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
int N;
double x[5003],y[5003],z[5003];
double X[5003],Y[5003],Z[5003];
int pl[5003];
double sqr(double x){return x*x;}
double dis(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
bool incircle(double Ox,double Oy,double x,double y,double R){return dis(Ox,Oy,x,y)<=R;}
void solve(double &x,double &y,double a,double b,double c,double d,double e,double f){
	y=(f*a-c*d)/(b*d-e*a);
	x=(f*b-c*e)/(a*e-b*d);
}
double work(double x[],double y[]){
	double R=0,Ox=0,Oy=0;
	for(int i=1;i<=N;++i)
		if(!incircle(Ox,Oy,x[i],y[i],R)){
			Ox=x[i];Oy=y[i];R=0;
			for(int j=1;j<i;++j)
				if(!incircle(Ox,Oy,x[j],y[j],R)){
					Ox=(x[i]+x[j])/2;
					Oy=(y[i]+y[j])/2;
					R=dis(Ox,Oy,x[i],y[i]);
					for(int k=1;k<j;++k)
						if(!incircle(Ox,Oy,x[k],y[k],R)){
							solve(Ox,Oy,x[i]-x[j],y[i]-y[j],(sqr(x[j])+sqr(y[j])-sqr(x[i])-sqr(y[i]))/2,x[i]-x[k],y[i]-y[k],(sqr(x[k])+sqr(y[k])-sqr(x[i])-sqr(y[i]))/2);
							R=dis(x[i],y[i],Ox,Oy);
						}
				}
		}
	return R*2;
}
int main(){
	#ifdef FILEIO
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;++i)
		scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
	for(int i=1;i<=N;++i)
		pl[i]=i;
	random_shuffle(pl+1,pl+N+1);
	for(int i=1;i<=N;++i)
		X[i]=x[pl[i]],Y[i]=y[pl[i]],Z[i]=z[pl[i]];
	double ans=9999;
	ans=min(ans,work(X,Y));
	ans=min(ans,work(Y,Z));
	ans=min(ans,work(Z,X));
	printf("%lf\n",ans);
	return 0;
}