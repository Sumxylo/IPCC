#include<iostream>
#include<string>
#include<map>
using namespace std;
struct lnode{
	string s;
	lnode *next,*prev;
};
struct Linklist{
	lnode *head,*tail;
	lnode* append(string s){
		tail->next=new lnode;
		tail->next->prev=tail;
		tail=tail->next;
		tail->s=s;
		tail->next=NULL;
		return tail;
	}
	void remove(lnode *p){
		p->prev->next=p->next;
		if(p->next)
			p->next->prev=p->prev;
		else
			tail=p->prev;
		free(p);
	}
}L;
map<string,lnode*> mp;
int main(){
	L.head=L.tail=new lnode;
	int n;
	cin>>n;
	string cmd,arg;
	for(int i=0;i<n;++i){
		cin>>cmd;
		if(cmd=="touch"){
			cin>>arg;
			if(mp.find(arg)==mp.end())
				mp[arg]=L.append(arg);
		}else if(cmd=="rm"){
			cin>>arg;
			map<string,lnode*>::iterator mpp=mp.find(arg);
			if(mpp!=mp.end()){
				L.remove(mpp->second);
				mp.erase(mpp);
			}
		}else if(cmd=="rename"){
			cin>>cmd>>arg;
			map<string,lnode*>::iterator mpp=mp.find(cmd);
			map<string,lnode*>::iterator mpq=mp.find(arg);
			if(mpp!=mp.end()&&mpq==mp.end()){
				mpp->second->s=arg;
				mp[arg]=mpp->second;
				mp.erase(mpp);
			}
		}else if(cmd=="ls"){
			for(lnode *p=L.head->next;p;p=p->next)
				cout<<p->s<<endl;
		}
	}
	return 0;
}