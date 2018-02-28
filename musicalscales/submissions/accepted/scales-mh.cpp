#include <bits/stdc++.h>
using namespace std;

vector<string> scales={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
vector<int> p={0,2,4,5,7,9,11};
vector<int> notes;
vector<int> ok;

bool in(int note, int major){
	for(int i:p)
		if((major+i)%12==note)return 1;
	return 0;
}

int main(){
	int n;cin>>n;
	notes.assign(n,-1);
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int id=0;id<12;id++)if(scales[id]==s)notes[i]=id;
	}
	ok.assign(12,1);
	int okc=12;
	for(int i=0;i<12;i++){
		for(int j=0;j<n;j++)if(!in(notes[j],i)){ok[i]=0;okc--;goto alright;}
		alright:;
	}
	for(int i=0;i<12;i++){
		if(ok[i])cout<<scales[i]<<' ';
	}
	if(okc==0)cout<<"none";
	cout<<endl;
}
