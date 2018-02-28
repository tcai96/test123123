#include <bits/stdc++.h>
using namespace std;

string name="divideby100";
int maxn=1e6-1;

vector<int> seeds{924,1397,31,6987,321,687,8413,987,4132,065,7813,268,130,357,6842};

int main(){
	cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		file<<(char)((rand()%9)+'1');
		int n=rand()%maxn;
		for(int i=0;i<n;i++)file<<(char)(rand()%10+'0');
		int m=rand()%maxn;
		file<<endl;
		file<<'1';
		for(int i=0;i<m;i++)file<<'0';
		file<<endl;
		file.close();
	}
}
