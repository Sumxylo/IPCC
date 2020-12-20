#include<cstdio>
#include<cstdlib>
void rd(int& a){
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	a=0;
	for(;c>='0'&&c<='9';c=getchar())
		a=a*10+c-'0';
}
int n;
struct node{
	int data,id;
	node* next;
};
struct bucket{
	node *head,*tail;
}bk[1024];
void collect(node& p){
	p.next=NULL;
	node *tail=&p;
	for(int i=1023;i>=0;--i)
		if(bk[i].head){
			tail->next=bk[i].head;
			tail=bk[i].tail;
			bk[i].head=bk[i].tail=NULL;
		}
}
void distribute(node& p,int d){
	for(node *q=p.next;q;){
		node *pnxt=q->next;
		int pl=(q->data>>(10*d))&1023;
		if(!bk[pl].head){
			bk[pl].head=bk[pl].tail=q;
		}else{
			bk[pl].tail->next=q;
			bk[pl].tail=q;
		}
		bk[pl].tail->next=NULL;
		q=pnxt;
	}
}
int main(){
	rd(n);
	int t,k;
	for(int i=0;i<n;++i){
		rd(t);rd(k);
		if(!bk[t].head){
			bk[t].head=(node*)malloc(sizeof(node));
			bk[t].tail=bk[t].head;
		}else{
			bk[t].tail->next=(node*)malloc(sizeof(node));
			bk[t].tail=bk[t].tail->next;
		}
		bk[t].tail->data=t*k;
		bk[t].tail->id=i+1;
	}
	node p;
	collect(p);
	distribute(p,0);
	collect(p);
	distribute(p,1);
	collect(p);
	for(node *q=p.next;q;q=q->next)
		printf("%d ",q->id);
	return 0;
}