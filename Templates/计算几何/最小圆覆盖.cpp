/*
最小圆覆盖：给定若干个二维平面上的点，求能将这些点全部覆盖的半径最小的圆的圆心以及半径。
注意：将点集先Random Shuffle以保证时间复杂度
时间：O(n)；空间：O(n)
全局变量：无
STL：无
*/
#include<cmath>
double dis(double x1,double y1,double x2,double y2){return sqrt(pow(x1-x2,2)+pow(y1-y2,2));}
bool incircle(double Ox,double Oy,double x,double y,double R){return dis(Ox,Oy,x,y)<=R;}
void solve(double &x,double &y,double a,double b,double c,double d,double e,double f){
	y=(f*a-c*d)/(b*d-e*a);
	x=(f*b-c*e)/(a*e-b*d);
}
double work(double x[],double y[],int N){//x,y为点集中各个点的坐标，N为总点数
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
							solve(Ox,Oy,x[i]-x[j],y[i]-y[j],(pow(x[j],2)+pow(y[j],2)-pow(x[i],2)-pow(y[i],2))/2,x[i]-x[k],y[i]-y[k],(pow(x[k],2)+pow(y[k],2)-pow(x[i],2)-pow(y[i],2))/2);
							R=dis(x[i],y[i],Ox,Oy);
						}
				}
		}
	return R;//R为圆半径，Ox、Oy为圆心坐标
}