#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n,p0,p1,known,c0,c1;
vi s0,s1,revealed;

int match(int x){return x+((x%2)?-1:1);}

bool play(int& player, int& cchoice, vi& choice){
	if(known!=-1){player+=2;known=-1;return true;}
	while(1)if(revealed[choice[cchoice]])cchoice++;else break;
	int card0=choice[cchoice];
	revealed[card0]=1;
	if(revealed[match(card0)]){player+=2;return true;}
	while(1)if(revealed[choice[cchoice]])cchoice++;else break;
	int card1=choice[cchoice];
	revealed[card1]=1;
	if(card0>>1==card1>>1){player+=2;return true;}
	if(revealed[match(card1)])known=card1;
	return false;
}

int main(){
	cin>>n;
	p0=p1=c0=c1=0;
	known=-1;
	s0.assign(2*n,0);
	s1.assign(2*n,0);
	revealed.assign(2*n,0);
	for(int i=0;i<2*n;i++)cin>>s0[i];
	for(int i=0;i<2*n;i++)cin>>s1[i];
	int turn=0;
	while(p0+p1<2*n){
		while(1){
			bool playagain=play(turn?p1:p0,turn?c1:c0,turn?s1:s0);
		//	cout<<turn<<'\t'<<(turn?c1:c0)<<'\t'<<playagain<<endl;
			if(!playagain)break;
			if(p0+p1==2*n)break;
		}
		turn=(turn+1)%2;
	}
	if(p0==p1)cout<<"-1"<<endl;
	else cout<<((p0<p1)?"1":"0")<<endl;
}
